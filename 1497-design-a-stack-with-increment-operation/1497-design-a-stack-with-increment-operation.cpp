#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class CustomStack {
    int n, *arr, top;
public:
    CustomStack(int maxSize) : n(maxSize), top(0) { arr = new int[n]; }

    void push(int x) { if(top < n) arr[top++] = x; }

    int pop() {
        if(top > 0) return arr[--top];
        return -1;
    }

    void increment(int k, int val) {
        for(int i=0; i<k && i<top; i++){
            arr[i] += val;
        }
    }
    
    // ~CustomStack() { delete[] arr; }
};