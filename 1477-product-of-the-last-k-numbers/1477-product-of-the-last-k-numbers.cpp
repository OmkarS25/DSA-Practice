class ProductOfNumbers {
private:
    vector<int> v; // We will store the prefix product
    volatile int n = 0;

public:
    ProductOfNumbers() {
        v.push_back(1);
        n = 0;
    }

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