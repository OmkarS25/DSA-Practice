struct UnionFind {  // disjoint set joiner
  UnionFind(uint n): roots(n), sizes(n, 1) { iota(roots.begin(), roots.end(), 0); }
  uint find(uint x) { return x==roots[x] ? x : roots[x] = find(roots[x]); }
  bool join(uint x, uint y) { // return true if joining sets containing x & y
    x = find(x);  y = find(y);  // replace with roots
    if (x==y) return false;   // nothing to do
    if (sizes[x] > sizes[y])  { sizes[x] += sizes[y]; roots[y]=x; }
    else                      { sizes[y] += sizes[x]; roots[x]=y; }
    return true;  // did join
  }
  vector<uint> roots, sizes;
};

struct Solution {
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    map<int, pair<uint, int>> q;  // query val, index from start, res
    auto tl=grid[0][0];
    for (auto& i:queries)  if (i>tl) q[i];
    if (q.empty()) return vector<int>(queries.size());
    uint q_index=0;
    for (auto& i:q) i.second.first = q_index++;
    uint nr=grid.size(), nc=grid[0].size(), nq=q.size();
    auto itq_b=q.begin();     auto itq_e=q.end();
    vector<unordered_set<uint>> vals_at(nq-1);   // flat indices of grid values in q intervals
    int low_val=itq_b->first;
    UnionFind uf(nr*nc);
    auto iti=grid.begin();
    for (uint i=0; i<nr; ++i, ++iti) {
      auto itij = iti->begin();
      for (uint j=0; j<nc; ++j, ++itij) {
        auto it=q.upper_bound(*itij);
        uint ind = i*nc+j;
        if (it==itq_b) {
          if (i>0 and grid[i-1][j]<low_val)     uf.join(ind, ind-nc);
          if (i<nr-1 and grid[i+1][j]<low_val)  uf.join(ind, ind+nc);
          if (j>0 and (*iti)[j-1]<low_val)      uf.join(ind, ind-1);
          if (j<nc-1 and (*iti)[j+1]<low_val)   uf.join(ind, ind+1);
        }
        else if (it!=itq_e) vals_at[it->second.first-1].insert(ind);
      }
    }
    auto itq=itq_b;
    itq++->second.second=uf.sizes[uf.find(0)];
    for (uint i=1; i<nq; ++i, ++itq) {
      auto bound=itq->first;
      for (auto& i:vals_at[i-1]) {  // i is flat index
        uint r=i/nc, c=i%nc;
        if (r>0 and grid[r-1][c]<bound)     uf.join(i, i-nc);
        if (r<nr-1 and grid[r+1][c]<bound)  uf.join(i, i+nc);
        if (c>0 and grid[r][c-1]<bound)     uf.join(i, i-1);
        if (c<nc-1 and grid[r][c+1]<bound)  uf.join(i, i+1);
      }
      itq->second.second = uf.sizes[uf.find(0)];
    }
    vector<int> res;  res.reserve(queries.size());
    for (auto& i:queries) res.push_back(q[i].second);
    return res;
  }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();