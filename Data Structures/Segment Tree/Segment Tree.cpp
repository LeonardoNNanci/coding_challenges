template <class T>
class SegmentTree
{
private:
    T neutral = INT_MIN;
    int N;
    vector<T> st, arr;

    int left(int i)
    {
        return i * 2;
    }

    int right(int i)
    {
        return i * 2 + 1;
    }

    // The actual operation in the seg tree
    T op(T left, T right)
    {
        return max(left, right);
    }

    T rangeQuery(int i, int low, int high, int qlow, int qhigh)
    {
        if (qlow > high || qhigh < low)
            return neutral;
        if (low >= qlow && high <= qhigh)
            return st[i];

        int mid = (low + high) / 2;
        T cl = rangeQuery(left(i), low, mid, qlow, qhigh);
        T cr = rangeQuery(right(i), mid + 1, high, qlow, qhigh);
        return op(cl, cr);
    }

    void build(int i, int low, int high)
    {
        if (low == high)
        {
            st[i] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        int l = left(i), r = right(i);
        build(l, low, mid);
        build(r, mid + 1, high);
        st[i] = op(st[l], st[r]);
    }

public:
    SegmentTree(vector<T> &base)
    {
        arr = base;
        N = base.size();
        st.assign(N * 4, neutral);
        build(1, 0, N - 1);
    }

    T rangeQuery(int qlow, int qhigh)
    {
        return rangeQuery(1, 0, N - 1, qlow, qhigh);
    }
};