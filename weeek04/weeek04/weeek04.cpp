// weeek04.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "KMatrix.h"
using std::cout;
using std::cin;
int IsNumber(int a)
{
    if (a > 0)return 1;
    else return 0;
}
int Isnumber(double a)
{
    if (a > 0)return 1;
    else return 0;
}
void Menu()
{
    cout << "-------------------" << endl;
    cout << "请根据序号选择你想要进行的操作" << endl;
    cout << "1:获取矩阵的行数" << endl;
    cout << "2:获取矩阵的列数" << endl;
    cout << "3:修改矩阵指定位置的值" << endl;
    cout << "4:获取矩阵指定位置的值" << endl;
    cout << "5:删除指定的矩阵的行" << endl;
    cout << "6:删除指定的矩阵的列" << endl;
    cout << "7:矩阵的加法运算" << endl;
    cout << "8:矩阵的减法运算" << endl;
    cout << "9:矩阵的乘法运算" << endl;
    cout << "10:矩阵的转置" << endl;
    cout << "11:打印矩阵" << endl;
    cout << "0:退出" << endl;
}

int main()
{
    cout << "请选择1、矩阵double型，2、矩阵int型"<<endl;
    int chooseType, chooseMenu = 0; cin >> chooseType;
    if (chooseType == 1)
    {
        cout << "创建矩阵1,输入矩阵1的行列" << endl;
        int row1, col1; cin >> row1 >> col1;
        KMatrix <double>Matrix1(row1, col1);
        Matrix1.inputMatrix();

        cout << "创建矩阵2,输入矩阵2的行列" << endl;
        int row2, col2; cin >> row2 >> col2;
        KMatrix <double>Matrix2(row2, col2);
        Matrix2.inputMatrix();

        while (1)
        {
            cout << endl<<endl;
            Menu();
            cout << "根据提示输入相应的数字" << endl;
            cin >> chooseMenu;
            switch (chooseMenu)
            {
                case 1:
                {
                    cout << "矩阵1的行：" << Matrix1.getRows() << endl << endl;
                    cout << "矩阵2的行：" << Matrix2.getRows() << endl<<endl;
                    break;
                }

                case 2:
                {
                    cout << "矩阵1的列：" << Matrix1.getCols() << endl << endl;
                    cout << "矩阵2的列：" << Matrix2.getCols() << endl << endl;
                    break;
                }

                case 3:
                {
                    
                    cout <<endl<<"输入：1、修改矩阵1；2、修改矩阵2"<<endl;
                    int aChoose; cin >> aChoose; int modRow, modCol; double modVal;
                    if (aChoose==1)
                    {
                        cout << "输入矩阵1要修改的行列的位置和修改后的值" << endl;
                        cin >> modRow >> modCol>>modVal;
                        if (IsNumber(modRow) && IsNumber(modCol))Matrix1.setData(modRow - 1, modCol - 1, modVal);
                        else if (!IsNumber(modRow) || !IsNumber(modCol)) cout << "数据不合法，修改失败" << endl;
                        cout << endl << "修改后的矩阵1" << endl; Matrix1.print(); cout << endl;
                    }
                    if (aChoose == 2)
                    {
                        cout << "输入矩阵2要修改的行列的位置和修改后的值" << endl;
                        cin >> modRow >> modCol >> modVal;
                        if (IsNumber(modRow) && IsNumber(modCol))Matrix2.setData(modRow - 1, modCol - 1, modVal);
                        else if(!IsNumber(modRow)||!IsNumber(modCol)) cout<< "数据不合法，修改失败" << endl;
                        cout << endl << "修改后的矩阵2" << endl; Matrix2.print(); cout << endl;
                    }
                    if(aChoose != 1&&aChoose!=2) cout << "输入不合法" << endl << endl;
                    break;
                }

                case 4:
                {
                    cout <<endl<< "输入：1、获取矩阵1指定位置的值；2、获取矩阵2指定位置的值" << endl;
                    int aChoose; cin >> aChoose; int getRow, getCol; double getVal;
                    if (aChoose == 1)
                    {
                        cout << "输入矩阵1要获取的行列的位置的值" << endl;
                        cin >> getRow >> getCol;
                        if (IsNumber(getRow) && IsNumber(getCol))cout<<"该处的值为"<<Matrix1.getData(getRow - 1, getCol - 1)<<endl;
                        else cout << "数据不合法，修改失败" << endl << endl;
                    }
                    if (aChoose == 2)
                    {
                        cout << "输入矩阵2要获取的行列的位置的值" << endl;
                        cin >> getRow >> getCol;
                        if (IsNumber(getRow) && IsNumber(getCol))cout << "该处的值为" << Matrix2.getData(getRow - 1, getCol - 1) << endl;
                        else cout << "数据不合法，修改失败" << endl << endl;
                    }
                    if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                    break;
                }
                case 5:
                {
                    cout <<endl<< "输入：1、删除矩阵1指定行；2、删除矩阵2指定行" << endl;
                    int aChoose; cin >> aChoose; int delRow;
                    if (aChoose == 1)
                    {
                        cout << "输入矩阵1要删除的行的值" << endl;
                        cin >> delRow;
                        cout << "删除前的矩阵1" << endl<<endl; Matrix1.print();
                        if (IsNumber(delRow))Matrix1.eraseRow(delRow-1);
                        else cout << "数据不合法，修改失败" << endl << endl;
                        cout << "删除后的矩阵" << endl; Matrix1.print(); cout << endl << endl;
                    }
                    if (aChoose == 2)
                    {
                        cout << "输入矩阵2要删除的行的值" << endl;
                        cin >> delRow;
                        cout << "删除前的矩阵2" << endl << endl; Matrix2.print();
                        if (IsNumber(delRow))Matrix2.eraseRow(delRow-1);
                        else cout << "数据不合法，修改失败" << endl << endl;
                        cout << "删除后的矩阵" << endl; Matrix2.print(); cout << endl << endl;
                    }
                    if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                    break;
                }
                case 6:
                {
                    cout <<endl<< "输入：1、删除矩阵1指定列；2、删除矩阵2指定列" << endl;
                    int aChoose; cin >> aChoose; int delCol;
                    if (aChoose == 1)
                    {
                        cout << "输入矩阵1要删除的列的值" << endl;
                        cin >> delCol;
                        cout << "删除前的矩阵1" << endl << endl; Matrix1.print();
                        if (IsNumber(delCol))Matrix1.eraseColumn(delCol-1);
                        else cout << "数据不合法，修改失败" << endl << endl;
                        cout << "删除后的矩阵" << endl; Matrix1.print(); cout << endl << endl;
                    }
                    if (aChoose == 2)
                    {
                        cout << "输入矩阵2要删除的列的值" << endl;
                        cin >> delCol;
                        cout << "删除前的矩阵2" << endl << endl; Matrix2.print();
                        if (IsNumber(delCol))Matrix2.eraseColumn(delCol-1);
                        else cout << "数据不合法，修改失败" << endl << endl;
                        cout << "删除后的矩阵" << endl; Matrix2.print(); cout << endl << endl;
                    }
                    if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                    break;
                }
                case 7:
                {
                    if (Matrix1.getRows() != Matrix2.getRows() || Matrix1.getCols() != Matrix2.getCols())
                        cout <<endl<< "行列不相同！" << endl;
                    else
                    {
                        cout << "矩阵1和2的加法：" << endl;
                        KMatrix<double> addMatrix = Matrix1 + Matrix2;
                        addMatrix.print(); cout << endl;
                    }
                    break;
                }
                case 8:
                {
                    if (Matrix1.getRows() != Matrix2.getRows() || Matrix1.getCols() != Matrix2.getCols())
                        cout << endl<<"行列不相同！" << endl;
                    else
                    {
                        cout << "矩阵1和2的减法：" << endl;
                        KMatrix<double> subMatrix = Matrix1 - Matrix2;
                        subMatrix.print(); cout << endl;
                    }
                    break;
                }
                case 9:
                {
                    cout << endl<<"矩阵1和2的乘法：" << endl;
                    if (Matrix1.getCols() != Matrix2.getRows())
                        cout << "A的行和B的列的值不相同！" << endl<<endl;
                    else
                    {
                        KMatrix<double> mulMatrix = Matrix1 * Matrix2;
                        mulMatrix.print(); cout << endl;
                    }
                    break;
                }
                case 10:
                {
                    cout << "输入：1、转置矩阵1；2、转置矩阵2;"<< endl;
                    int aChoose; cin >> aChoose;
                    if (aChoose == 1)
                    {
                        cout <<endl<< "转置前的矩阵1" << endl << endl; Matrix1.print();
                        //KMatrix<double>* matrix = new KMatrix<double>(Matrix1.getRows(), Matrix1.getCols());
                        KMatrix<double> matrixTranspose1 =Matrix1.transpose(Matrix1);
                        Matrix1 = matrixTranspose1;
                        cout << "转置后的矩阵1" << endl; matrixTranspose1.print(); cout << endl<<endl;
                    }
                    if (aChoose == 2)
                    {
                        cout << "转置前的矩阵2" << endl << endl; Matrix2.print();
                        KMatrix<double> matrixTranspose2 = Matrix2.transpose(Matrix2);
                        Matrix2 = matrixTranspose2;
                        cout << "转置后的矩阵2" << endl; matrixTranspose2.print(); cout << endl<<endl;
                    }
                    if (aChoose != 1 && aChoose != 2) cout << "输入错误" << endl<<endl;
                    break;
                }
                case 11:
                {
                    cout <<endl<< "输入：1、展示矩阵1；2、展示矩阵2;" << endl;
                    int aChoose; cin >> aChoose;
                    if (aChoose == 1)cout << endl; Matrix1.print();
                    if (aChoose == 2)cout << endl; Matrix2.print();
                    if (aChoose!=1&&aChoose!=2) cout << "输入错误" << endl;
                    break;
                }

            }
        }

       
    }
    if (chooseType == 2)
    {
        cout << "创建矩阵1,输入矩阵1的行列" << endl;
        int row1, col1; cin >> row1 >> col1;
        KMatrix <int>Matrix1(row1, col1);
        Matrix1.inputMatrix();

        cout << "创建矩阵2,输入矩阵2的行列" << endl;
        int row2, col2; cin >> row2 >> col2;
        KMatrix <int>Matrix2(row2, col2);
        Matrix2.inputMatrix();

        while (1)
        {
            cout << endl << endl;
            Menu();
            cout <<endl<< "根据提示输入相应的数字" << endl;
            cin >> chooseMenu;
            switch (chooseMenu)
            {
            case 1:
            {
                cout << "矩阵1的行：" << Matrix1.getRows() << endl << endl;
                cout << "矩阵2的行：" << Matrix2.getRows() << endl << endl;
                break;
            }

            case 2:
            {
                cout << "矩阵1的列：" << Matrix1.getCols() << endl << endl;
                cout << "矩阵2的列：" << Matrix2.getCols() << endl << endl;
                break;
            }

            case 3:
            {

                cout << endl << "输入：1、修改矩阵1；2、修改矩阵2" << endl;
                int aChoose; cin >> aChoose; int modRow, modCol; int modVal;
                if (aChoose == 1)
                {
                    cout << "输入矩阵1要修改的行列的位置和修改后的值" << endl;
                    cin >> modRow >> modCol >> modVal;
                    if (IsNumber(modRow) && IsNumber(modCol))Matrix1.setData(modRow - 1, modCol - 1, modVal);
                    else if (!IsNumber(modRow) || !IsNumber(modCol)) cout << "数据不合法，修改失败" << endl;
                    cout << endl << "修改后的矩阵1" << endl; Matrix1.print(); cout << endl;
                }
                if (aChoose == 2)
                {
                    cout << "输入矩阵2要修改的行列的位置和修改后的值" << endl;
                    cin >> modRow >> modCol >> modVal;
                    if (IsNumber(modRow) && IsNumber(modCol))Matrix2.setData(modRow - 1, modCol - 1, modVal);
                    else if (!IsNumber(modRow) || !IsNumber(modCol)) cout << "数据不合法，修改失败" << endl;
                    cout << endl << "修改后的矩阵2" << endl; Matrix2.print(); cout << endl;
                }
                if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                break;
            }

            case 4:
            {
                cout << endl << "输入：1、获取矩阵1指定位置的值；2、获取矩阵2指定位置的值" << endl;
                int aChoose; cin >> aChoose; int getRow, getCol; int getVal;
                if (aChoose == 1)
                {
                    cout << "输入矩阵1要获取的行列的位置的值" << endl;
                    cin >> getRow >> getCol;
                    if (IsNumber(getRow) && IsNumber(getCol))cout << "该处的值为" << Matrix1.getData(getRow - 1, getCol - 1) << endl;
                    else cout << "数据不合法，修改失败" << endl << endl;
                }
                if (aChoose == 2)
                {
                    cout << "输入矩阵2要获取的行列的位置的值" << endl;
                    cin >> getRow >> getCol;
                    if (IsNumber(getRow) && IsNumber(getCol))cout << "该处的值为" << Matrix2.getData(getRow - 1, getCol - 1) << endl;
                    else cout << "数据不合法，修改失败" << endl << endl;
                }
                if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                break;
            }
            case 5:
            {
                cout << endl << "输入：1、删除矩阵1指定行；2、删除矩阵2指定行" << endl;
                int aChoose; cin >> aChoose; int delRow;
                if (aChoose == 1)
                {
                    cout << "输入矩阵1要删除的行的值" << endl;
                    cin >> delRow;
                    cout << "删除前的矩阵1" << endl << endl; Matrix1.print();
                    if (IsNumber(delRow))Matrix1.eraseRow(delRow - 1);
                    else cout << "数据不合法，修改失败" << endl << endl;
                    cout << "删除后的矩阵" << endl; Matrix1.print(); cout << endl << endl;
                }
                if (aChoose == 2)
                {
                    cout << "输入矩阵2要删除的行的值" << endl;
                    cin >> delRow;
                    cout << "删除前的矩阵2" << endl << endl; Matrix2.print();
                    if (IsNumber(delRow))Matrix2.eraseRow(delRow - 1);
                    else cout << "数据不合法，修改失败" << endl << endl;
                    cout << "删除后的矩阵" << endl; Matrix2.print(); cout << endl << endl;
                }
                if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                break;
            }
            case 6:
            {
                cout << endl << "输入：1、删除矩阵1指定列；2、删除矩阵2指定列" << endl;
                int aChoose; cin >> aChoose; int delCol;
                if (aChoose == 1)
                {
                    cout << "输入矩阵1要删除的列的值" << endl;
                    cin >> delCol;
                    cout << "删除前的矩阵1" << endl << endl; Matrix1.print();
                    if (IsNumber(delCol))Matrix1.eraseColumn(delCol - 1);
                    else cout << "数据不合法，修改失败" << endl << endl;
                    cout << "删除后的矩阵" << endl; Matrix1.print(); cout << endl << endl;
                }
                if (aChoose == 2)
                {
                    cout << "输入矩阵2要删除的列的值" << endl;
                    cin >> delCol;
                    cout << "删除前的矩阵2" << endl << endl; Matrix2.print();
                    if (IsNumber(delCol))Matrix2.eraseColumn(delCol - 1);
                    else cout << "数据不合法，修改失败" << endl << endl;
                    cout << "删除后的矩阵" << endl; Matrix2.print(); cout << endl << endl;
                }
                if (aChoose != 1 && aChoose != 2) cout << "输入不合法" << endl << endl;
                break;
            }
            case 7:
            {
                if (Matrix1.getRows() != Matrix2.getRows() || Matrix1.getCols() != Matrix2.getCols())
                    cout << endl << "行列不相同！" << endl;
                else
                {
                    cout << "矩阵1和2的加法：" << endl;
                    KMatrix<int> addMatrix = Matrix1 + Matrix2;
                    addMatrix.print(); cout << endl;
                }
                break;
            }
            case 8:
            {
                if (Matrix1.getRows() != Matrix2.getRows() || Matrix1.getCols() != Matrix2.getCols())
                    cout << endl << "行列不相同！" << endl;
                else
                {
                    cout << "矩阵1和2的减法：" << endl;
                    KMatrix<int> subMatrix = Matrix1 - Matrix2;
                    subMatrix.print(); cout << endl;
                }
                break;
            }
            case 9:
            {
                cout << endl << "矩阵1和2的乘法：" << endl;
                if (Matrix1.getCols() != Matrix2.getRows())
                    cout << "A的行和B的列的值不相同！" << endl << endl;
                else
                {
                    KMatrix<int> mulMatrix = Matrix1 * Matrix2;
                    mulMatrix.print(); cout << endl;
                }
                break;
            }
            case 10:
            {
                cout << "输入：1、转置矩阵1；2、转置矩阵2;" << endl;
                int aChoose; cin >> aChoose;
                if (aChoose == 1)
                {
                    cout << endl << "转置前的矩阵1" << endl << endl; Matrix1.print();
                    KMatrix<int> matrixTranspose1 = Matrix1.transpose(Matrix1);
                    Matrix1 = matrixTranspose1;
                    cout << "转置后的矩阵1" << endl; matrixTranspose1.print(); cout << endl << endl;
                }
                if (aChoose == 2)
                {
                    cout << "转置前的矩阵2" << endl << endl; Matrix2.print();
                    KMatrix<int> matrixTranspose2 = Matrix2.transpose(Matrix2);
                    Matrix2 = matrixTranspose2;
                    cout << "转置后的矩阵2" << endl; matrixTranspose2.print(); cout << endl << endl;
                }
                if (aChoose != 1 && aChoose != 2) cout << "输入错误" << endl << endl;
                break;
            }
            case 11:
            {
                cout << endl << "输入：1、展示矩阵1；2、展示矩阵2;" << endl;
                int aChoose; cin >> aChoose;
                if (aChoose == 1)cout << endl; Matrix1.print();
                if (aChoose == 2)cout << endl; Matrix2.print();
                if (aChoose != 1 && aChoose != 2) cout << "输入错误" << endl;
                break;
            }

            }
        }


    }
    else if (chooseType != 1 && chooseType != 2)cout << "输入错误！" << endl;
    return 0;
}


