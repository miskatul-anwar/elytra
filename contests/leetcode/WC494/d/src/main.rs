pub fn count_good_subarrays(nums: Vec<i32>) -> i64 {
    let n = nums.len();

    // Step 1: Find left boundary where nums[i] is the maximum
    let mut l_max = vec![-1_i32; n];
    let mut stack: Vec<usize> = Vec::new();
    for i in 0..n {
        while let Some(&idx) = stack.last() {
            if nums[idx] < nums[i] {
                stack.pop();
            } else {
                break;
            }
        }
        if let Some(&idx) = stack.last() {
            l_max[i] = idx as i32;
        }
        stack.push(i);
    }

    // Step 2: Find right boundary where nums[i] is the strictly maximum
    // (Using strictly greater prevents double counting duplicate max elements)
    let mut r_max = vec![n as i32; n];
    stack.clear();
    for i in (0..n).rev() {
        while let Some(&idx) = stack.last() {
            if nums[idx] <= nums[i] {
                stack.pop();
            } else {
                break;
            }
        }
        if let Some(&idx) = stack.last() {
            r_max[i] = idx as i32;
        }
        stack.push(i);
    }

    // Step 3: Find left boundary where elements are sub-masks of nums[i]
    let mut l_bad = vec![-1_i32; n];
    let mut last_seen = vec![-1_i32; 30];
    for i in 0..n {
        for k in 0..30 {
            if (nums[i] >> k) & 1 == 0 {
                l_bad[i] = l_bad[i].max(last_seen[k]);
            }
        }
        for k in 0..30 {
            if (nums[i] >> k) & 1 == 1 {
                last_seen[k] = i as i32;
            }
        }
    }

    // Step 4: Find right boundary where elements are sub-masks of nums[i]
    let mut r_bad = vec![n as i32; n];
    let mut next_seen = vec![n as i32; 30];
    for i in (0..n).rev() {
        for k in 0..30 {
            if (nums[i] >> k) & 1 == 0 {
                r_bad[i] = r_bad[i].min(next_seen[k]);
            }
        }
        for k in 0..30 {
            if (nums[i] >> k) & 1 == 1 {
                next_seen[k] = i as i32;
            }
        }
    }

    // Step 5: Calculate total good subarrays
    let mut total_good = 0_i64;
    for i in 0..n {
        // The valid window boundaries
        let left_bound = l_max[i].max(l_bad[i]) + 1;
        let right_bound = r_max[i].min(r_bad[i]) - 1;

        // Number of combinations
        let left_choices = (i as i32 - left_bound + 1) as i64;
        let right_choices = (right_bound - i as i32 + 1) as i64;

        if left_choices > 0 && right_choices > 0 {
            total_good += left_choices * right_choices;
        }
    }

    total_good
}
fn main() {
    println!("Hello, world!");
}
