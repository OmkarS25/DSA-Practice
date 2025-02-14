class ProductOfNumbers {
    vector<int> v {1}; // We will store the prefix product
    int n = 0;

public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            v = {1};
            n = 0;
        } 
        else v.push_back(v[n++] * num);
    }

    int getProduct(int k) {
        return (k > n) ? 0 : (v[n] / v[n - k]);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();