//  avoid "not used" warning
template<typename T>
void play(const T&)
{}

int main()
{
    int* p = new int(5);
    play(p);
    return 0;
}