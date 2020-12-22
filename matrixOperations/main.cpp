#include <iostream>
#include <vector>
using namespace std;
class Matrix {
public:
    Matrix(){
        columns=0;
        rows=0;
    }
    Matrix(int num_rows,int num_cols){
        if(num_rows<0){
            throw out_of_range("row");
        }else if(num_cols<0){
            throw out_of_range("col");
        }
        rows=num_rows;
        columns=num_cols;
        for(int i=0;i<num_rows;i++){
            vector<int> null;
            matrix.push_back(null);
            for(int j=0;j<num_cols;j++){
                matrix[i].push_back(0);
            }
        }
    }
    void Reset(int num_rows,int num_cols){
        if(num_rows<0){
            throw out_of_range("row");
        }else if(num_cols<0){
            throw out_of_range("col");
        }
        vector<vector<int>> curentMatrix;
        rows=num_rows;
        columns=num_cols;
        for(int i=0;i<num_rows;i++){
            vector<int> null;
            curentMatrix.push_back(null);
            for(int j=0;j<num_cols;j++){
                curentMatrix[i].push_back(0);
            }
        }
        matrix=curentMatrix;
    }
    int GetNumRows() const{
        return rows;
    }
    int GetNumColumns()const{
        return columns;
    }
    int At(int num_row,int num_col) const{
        if(num_row<0||num_row>rows){
            throw out_of_range("row");
        }else if(num_col<0||num_col>columns){
            throw out_of_range("col");
        }
        return matrix.at(num_row).at(num_col);
    }
    int& At(int num_row,int num_col) {
        if(num_row<0||num_row>rows){
            throw out_of_range("row");
        }else if(num_col<0||num_col>columns){
            throw out_of_range("col");
        }
        int& res=matrix.at(num_row).at(num_col);
        return res;
    }
private:
    int rows;
    int columns;
    vector<vector<int>> matrix;
};
ostream &operator<<(ostream &os, const Matrix & matrix)
{
    if(matrix.GetNumRows()==0||matrix.GetNumColumns()==0){
        os<<"0 0"<<endl;
    }else{
        os<<matrix.GetNumRows()<<" "<<matrix.GetNumColumns()<<endl;
    }
    for (int i=0; i < matrix.GetNumRows(); i++)
    {
        for (int j=0; j < matrix.GetNumColumns(); j++) {
            os << matrix.At(i, j) << " ";
        }
        if(i!=matrix.GetNumRows()-1) {
            os << endl;
        }
    }
    return os;
}
istream& operator >>(istream&is,Matrix& matrix){
    int row_num,column_num;
    int nextValue;
    is>>row_num>>column_num;
    if(row_num<0){
        throw out_of_range("row");
    }
    else if(column_num<0){
        throw out_of_range("col");
    }
    if(is){
        matrix.Reset(row_num,column_num);
        for(int i=0;i<row_num;i++){
            for(int j=0;j<column_num;j++){
                is>>nextValue;
                matrix.At(i,j)=nextValue;
            }
        }
    }else{
        is.setstate(ios_base::failbit);
    }
    return is;
}
bool operator ==(const Matrix& left,const Matrix& right){
    if(left.GetNumColumns()==right.GetNumColumns()&&left.GetNumColumns()==0){
        return true;
    }else if(left.GetNumRows()==right.GetNumRows()&&left.GetNumRows()==0){
        return true;
    }
    else if(left.GetNumRows()==right.GetNumColumns()&&left.GetNumRows()==0){
        return true;
    }
    else if(left.GetNumColumns()==right.GetNumRows()&&left.GetNumColumns()==0){
        return true;
    }
    if((left.GetNumColumns()==right.GetNumColumns()) && (left.GetNumRows()==right.GetNumRows())) {
        for(int i=0;i<left.GetNumRows();i++){
            for(int j=0;j<left.GetNumColumns();j++){
                if(left.At(i,j)!=right.At(i,j)){
                    return false;
                }
            }
        }
        return true;
    }else{
        return false;
    }
}
Matrix operator +(const Matrix& left,const Matrix& right){
    if(left.GetNumColumns()==right.GetNumColumns()&&left.GetNumColumns()==0){
        return Matrix();
    }else if(left.GetNumRows()==right.GetNumRows()&&left.GetNumRows()==0){
        return Matrix();
    }
    else if(left.GetNumRows()==right.GetNumColumns()&&left.GetNumRows()==0){
        return Matrix();
    }
    else if(left.GetNumColumns()==right.GetNumRows()&&left.GetNumColumns()==0){
        return Matrix();
    }
    if(left.GetNumColumns()!=right.GetNumColumns()){
        throw invalid_argument("col");
    }
    else if (left.GetNumRows()!=right.GetNumRows()){
        throw invalid_argument("row");
    }
    Matrix curMatrix(left.GetNumRows(),left.GetNumColumns());
    for(int i=0;i<left.GetNumRows();i++){
        for(int j=0;j<left.GetNumColumns();j++){
            curMatrix.At(i,j)=left.At(i,j)+right.At(i,j);
        }
    }
    return curMatrix;
}
int main() {
    Matrix one(2,0);
    Matrix two(0,3);
    std::cout << (one + two) << std::endl;
    return 0;
};
