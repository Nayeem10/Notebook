class mint {
private:
    long long value;
    static int M;
    void normalize() {
        value %= M;
        if (value < 0) value += M;
    }
public:
    mint() : value(0) {}
    mint(int value) : value(value) { normalize(); }
    mint& operator=(int value) {
        this->value = value;
        normalize();
        return *this;
    }
    mint operator+(const mint& other) const { return mint(value + other.value); }
    mint operator+(int other) const { return mint(value + other); }
    mint operator-(const mint& other) const { return mint(value - other.value); }
    mint operator-(int other) const { return mint(value - other); }
    mint operator*(const mint& other) const { return mint(value * other.value % M); }
    mint operator*(int other) const { return mint(value * other % M); }
    mint operator/(const mint& other) const { return *this * mpow(other.value, -1); }
    mint operator/(int other) const { return *this * mpow(other, -1); }
 
    mint& operator+=(const mint& other) { value += other.value; normalize(); return *this; }
    mint& operator+=(int other) { value += other; normalize(); return *this; }
    mint& operator-=(const mint& other) { value -= other.value; normalize(); return *this; }
    mint& operator-=(int other) { value -= other; normalize(); return *this; }
    mint& operator*=(const mint& other) { value = (value * other.value) % M; normalize(); return *this; }
    mint& operator*=(int other) { value = (value * other) % M; normalize(); return *this; }
    mint& operator/=(const mint& other) { value = (value * mpow(other.value, -1)) % M; normalize(); return *this; }
    mint& operator/=(int other) { value = (value * mpow(other, -1)) % M; normalize(); return *this; }
 
    friend ostream& operator<<(ostream& os, const mint& var) { os << var.value; return os; }
    friend istream& operator>>(istream& is, mint& var) { is >> var.value; var.normalize(); return is; } 
};
 
int mint::M = mod;