template <class T>
class FenwickTree
{
private:
    T neutral = 0; // define according to the problem
    vector<T> ft;

    int LSOne(int i)
    {
        return i & (-i);
    }

    // define according to the problem
    T op(T x, T y)
    {
        return x + y;
    }

    // define according to the problem
    T opInv(T x, T y)
    {
        return x - y;
    }

public:
    FenwickTree(int N)
    {
        ft.assign(N + 1, neutral);
    }

    T rangeQuery(int i)
    {
        T acc = neutral;
        for (; i > 0; i -= LSOne(i))
            acc = op(acc, ft[i]);
        return acc;
    }

    T rangeQuery(int low, int high)
    {
        return opInv(rangeQuery(high + 1), (low == 0 ? neutral : rangeQuery(low)));
    }

    void update(int i, T val)
    {
        T prev = rangeQuery(i, i++);
        for (; i < ft.size(); i += LSOne(i))
        {
            ft[i] = opInv(ft[i], prev);
            ft[i] = op(ft[i], val);
        }
    }
};