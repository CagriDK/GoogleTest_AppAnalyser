

class Test
{
public:
    Test();

    template <typename T>
    static T sum(T a, T b)
    {
        T temp = a + b;
        return temp;
    }

    template <typename T>
    static  T sub(T a, T b)
    {
        T temp = a - b;
        return temp;
    }

    template <typename T>
    static T divide(T a, T b)
    {
        T temp = a / b;
        return temp;
    }

    template <typename T>
    static T mod(T a, T b)
    {
        T temp = a % b;
        return temp;
    }

    template <typename T>
    static T multiply(T a, T b)
    {
        T temp = a * b;
        return temp;
    }

private:
    int m_x;
};