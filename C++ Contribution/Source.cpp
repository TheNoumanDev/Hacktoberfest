////   print armstrong numbers between two numbers
//#include<iostream>
//#include<cmath>
//using namespace std;
//int checkValid(int x)
//{
//    while (x < 0)
//    {
//        cout << "Enter a Valid number: "; cin >> x;
//    }
//    return x;
//}
//int main()
//{
//    int start, end;
//    cout << "Enter a start number: "; cin >> start;
//    start = checkValid(start);
//    cout << "Enter a second number:"; cin >> end;
//    end = checkValid(end);
//    cout << "Armstrong numbers:\n";
//    while (start < end)
//    {
//        int temp = start, temp2 = start;
//        int sum = 0, count = 0;
//        while (temp != 0)
//        {
//            temp = temp / 10;
//            count++;
//        }
//        while (temp2 != 0)
//        {
//            sum += pow(temp2 % 10, count);
//            temp2 = temp2 / 10;
//        }
//        if (start == sum)
//        {
//            cout << start << " ";
//        }
//        start++;
//    }
//}