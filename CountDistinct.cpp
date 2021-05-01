
// Count distinct elements in an array

int countDistinct(int a[], int n) {
    set<int> mp(a, a+n);

    return mp.size();
}
