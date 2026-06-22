class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        ArrayDeque<Integer> q = new ArrayDeque<>(k + 1);
        int[] ans = new int[nums.length - k + 1];
        int l = 0, i = 0;

        for (int r = 0; r < nums.length; r++) {
            while (!q.isEmpty() && q.peekLast() < nums[r]) {
                q.pollLast();
            }
            q.offer(nums[r]);

            if (r - l + 1 > k) {
                if (q.peek() == nums[l])
                    q.poll();

                l++;
            }

            if (r - l + 1 == k) {
                ans[i++] = q.peek();
            }
        }

        return ans;
    }
}
