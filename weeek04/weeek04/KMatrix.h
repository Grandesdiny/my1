#pragma once
#include "iostream"
#include "vector"

using std::vector;
using std::cout;
using std::endl;
using std::cin;
template <typename T>
class KMatrix {
public:
    KMatrix(int row, int column, T value=0);
    void init();  //��ʼ��������Ϣ
    int  getRows() const; //�����
    int  getCols() const; //�����.
    void setData(int row, int col, T value);//����ֵ
    T getData(int row, int col); //�õ�ֵ
    void eraseRow(int row); //ɾ����
    void eraseColumn(int column);
    void inputMatrix()//��������ֵ
    {
        cout << "����" << this->m_row << "��" << this->m_column << "�о����" << "����" << endl;
        for (int i = 0; i < this->m_row; i++)
        {
            for (int j = 0; j < this->m_column; j++)
            {
                cin >> this->matrix[i][j];
            }
        }
    }

    template<typename T>
    friend KMatrix<T> operator+(KMatrix<T>a, KMatrix<T>b);

    template<typename T>
    friend KMatrix<T> operator-(KMatrix<T>a, KMatrix<T>b);
    template<typename T>
    friend KMatrix<T> operator*(KMatrix<T>a, KMatrix<T>b);
    template<typename T>
    KMatrix<T> transpose(KMatrix<T>a) const //ת��
    {
        KMatrix<T> newMatrix(a.m_column, a.m_row);
        for (int i = 0; i < a.m_column; i++) {
            for (int j = 0; j < a.m_row; j++) {
                newMatrix.matrix[i][j] = a.matrix[j][i];
            }
        }
        return newMatrix;
    }
    void print() const;//���

private:
    vector<vector<T>>matrix;
    int m_row = 0, m_column = 0;

};

template<typename T>
inline int KMatrix<T>::getRows() const {
    return m_row;
}

template<typename T>
inline int KMatrix<T>::getCols() const {
    return m_column;
}

template<typename T>
KMatrix<T>::KMatrix(int row, int column, T value) {
    m_row = row;
    m_column = column;
    matrix.resize(m_row);
    for (int i = 0; i < m_row; i++)
    {
        matrix[i].resize(m_column, value);
    }
}

template<typename T>
void KMatrix<T>::print() const {
    if (m_row == 0 || m_column == 0)
    {
        cout << "error!" << endl;
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < m_row; i++)
        {
            for (int j = 0; j < m_column; j++)
            {
                cout << matrix[i][j]<<"\t";
                cnt++;
                if (cnt % m_column == 0)
                       cout << endl;
            }
        }
        cout << endl;
    }
}

template<typename T>
void KMatrix<T>::setData(int row, int col, T value)
{
    matrix[row][col] = value;
}

template<typename T>
T KMatrix<T>::getData(int row, int col)
{
    return matrix[row][col];
}

template <typename T>
void KMatrix<T>::eraseRow(int row) //ɾ����
{
    auto it_begin = matrix.begin();
    matrix.erase(it_begin + row);
    m_row--;
}

template <typename T>
void KMatrix<T>::eraseColumn(int col) //ɾ����
{
    for (int i = 0; i < this->m_row; i++)
    {
        int cnt = 0;
        for (auto it_begin = matrix[i].begin(); it_begin != matrix[i].end();)
        {
            if (cnt == col)
            {
                it_begin = matrix[i].erase(it_begin);
            }
            else
            {
                it_begin++;
            }
            cnt++;
        }
    }
    m_column--;
}

template<typename T>
inline KMatrix<T> operator+(KMatrix<T> a, KMatrix<T> b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        cout << "��������֮����л��е�ֵ����Ӧ��" << endl;
    }
    else
    {
        KMatrix<T> tempMatrix(a.m_row, a.m_column);
        for (int i = 0; i < a.m_row; i++)
        {
            for (int j = 0; j < a.m_column; j++)
            {
                tempMatrix.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
            }
        }
        return tempMatrix;
    }
}

template <typename T>
inline KMatrix<T> operator-(KMatrix<T>a, KMatrix<T>b)
{
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
    {
        cout << "��������֮����л��е�ֵ����Ӧ��" << endl;
        exit(0);
    }
    else
    {
        KMatrix<T> tempMatrix(a.m_row,a.m_column);
        for (int i = 0; i < a.m_row; i++)
        {
            for (int j = 0; j < a.m_column; j++)
            {
                tempMatrix.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
            }
        }
        return tempMatrix;
    }
}

template <typename T>
inline KMatrix<T> operator*(KMatrix<T>a, KMatrix<T>b)
{
        KMatrix<T> tempMatrix(a.m_row, b.m_column);
        for (int i = 0; i < a.m_row; i++)
        {
            for (int j = 0; j < b.m_column; j++)
            {
                for (int k = 0; k < a.getCols(); k++)
                {
                    tempMatrix.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                }
            }
        }
        return tempMatrix;
  
}


