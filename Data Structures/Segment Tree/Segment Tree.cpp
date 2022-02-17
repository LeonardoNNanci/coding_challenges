template <class T>
class SegmentTree
{
private:
    T neutral = INT_MIN; // define according to the problem
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

    // define according to the problem
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

    void update(int i, int index, T val, int low, int high)
    {
        if (low == high)
        {
            st[i] = val;
            return;
        }

        int l = left(i), r = right(i);
        int mid = (low + high) / 2;
        if (index <= mid)
            update(l, index, val, low, mid);
        else
            update(r, index, val, mid + 1, high);
        st[i] = op(st[l], st[r]);
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

    void update(int index, T val)
    {
        update(1, index, val, 0, N - 1);
        arr[index] = val;
    }
};