impl Solution {
    pub fn check_string(s: String) -> bool {
        let mut seen_b = false;
        for ch in s.chars() {
            if ch == 'b' { seen_b = true; }
            if ch == 'a' && seen_b { return false; }
        }
        return true;
    }
}