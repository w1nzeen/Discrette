bool NOT(bool a)
{
    if (a == true ) return false;
    else return true;
}
bool AND(bool a, bool b)
{
    if (a == true && b == true) return true;
    else return false;
}

bool OR(bool a, bool b)
{
    if (a == true || b == true) return true;
    else return false;
}
bool IMP(bool a, bool b)
{
    if (a == true && b == false) return false;
    else return true;
}
bool EQU(bool a, bool b)
{
    if (a == b) return true;
    else return false;
}
bool XOR(bool a, bool b)
{
    if (a == b) return false;
    else return true;
}
bool x1(bool a, bool b)
{
    return XOR(NOT(a), NOT(b));
}
bool x2(bool a, bool b, bool c)
{
    return IMP(NOT(c), (XOR(NOT(a), NOT(b))));
}
bool F11(bool a, bool b, bool c) {
    return AND(IMP(a, b), (IMP(NOT(c), (XOR(NOT(a), NOT(b))))));
};