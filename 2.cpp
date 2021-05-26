#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string change_base(string num, int b1, int b2)
{
    string map = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", num_ten = "";
    
    // из b1 в десятичную
    int num_ten_temp = 0;
    for (int i = 0; i < num.size(); i++)
        num_ten_temp += ((isdigit(num[i])) ? (num[i] - '0') : (num[i] - 'A' + 10)) * (int)pow((double)b1, (double)(num.size() - i - 1));
    num_ten = to_string(num_ten_temp);

    // из десятичной в b2
    string num_b2;
    while (true)
    {
        int temp = num_ten_temp % b2;
        num_b2 = map[temp] + num_b2; 
        num_ten_temp /= b2;
        if (num_ten_temp < b2) 
        {
            num_b2 = map[num_ten_temp] + num_b2; 
            break;
        }
    }
    return num_b2;
}

int main()
{
    string num, out;
    int b1, b2;
    cin >> num >> b1 >> b2;

    if (b1 < 2 || b2 < 2 || b1 > 30 || b2 > 30)
    {
        cout << "b1 and b2 have to be in range from 2 to 30" << endl;
        return 0;
    }
    out = change_base(num, b1, b2);
    cout << out << endl;
}