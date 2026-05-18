class NumArray {
public:
    vector<int> tree;
    int n;
    
    int query(int start, int end, int node, int left, int right) {
        if (left <= start && right >= end) return tree[node];
        if (left > end || right < start) return 0;
        
        int mid = start + (end - start) / 2;
        return query(start, mid, 2 * node, left, min(right, mid)) +
               query(mid + 1, end, 2 * node + 1, max(mid + 1, left), right);
    }
    
    void build_tree(const vector<int>& nums, int start, int end, int node) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        
        int mid = start + (end - start) / 2;
        build_tree(nums, start, mid, 2 * node);
        build_tree(nums, mid + 1, end, 2 * node + 1);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void update_tree(int start, int end, int node, int idx, int val) {
        if (start == end && start == idx) {
            tree[node] = val;
            return;
        }
        
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update_tree(start, mid, 2 * node, idx, val);
        } else {
            update_tree(mid + 1, end, 2 * node + 1, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n + 1, 0);
        build_tree(nums, 0, n - 1, 1);
    }
    
    void update(int index, int val) {
        update_tree(0, n - 1, 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};
