#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
using namespace std;

#define PI 3.1415926535898

string LayPhanTu(string &BieuThuc)
{
    string ketqua;
    if(BieuThuc[0]=='(' || BieuThuc[0]==')'|| BieuThuc[0]=='+' || BieuThuc[0]=='-' || BieuThuc[0]=='*' || BieuThuc[0]=='/')
    //gặp toán tử và dấu ngoặc đóng mở 
    {
        ketqua.resize(1);//cấp phát 1 bộ nhớ cho kết quả
        ketqua=BieuThuc[0];//cho kết quả là toán tử hoặc dấu ngoặc đóng mở 
        BieuThuc.erase(0,1);//sau khi cấp phát thì xóa đi
        return ketqua;
    }

    //Khi gặp số thì đưa i số qua kết quả để lưu sau đó xóa đi i số bên Biểu thức
    int i=0;
    while(i<BieuThuc.size())
    {
        if(BieuThuc[i]>='0' && BieuThuc[i]<='9' || BieuThuc[i]=='.')//|| dấu . là dành cho số thực
        {
            ketqua.resize(i+1);//cấp phát vùng nhớ cho kết quả
            ketqua[i]=BieuThuc[i];
            i++;
        }
        else
            break;
    }
    BieuThuc.erase(0,i);//xóa đi i số cấp phát cho kết quả
    return ketqua;
}

int KiemTraPhanTu(string PhanTu)//hàm dùng để kiểm tra xem phần tử này là toán tử hay dấu ngoặc đóng mở hay là số
{
    if(PhanTu=="+" || PhanTu=="-" || PhanTu=="*" || PhanTu=="/")//là toán tử thì trả về 1
        return 1;
    else
    {
        if(PhanTu=="(" || PhanTu==")")//là dấu ngoặc đóng mở thì trả về -1
            return -1;
        return 0;//là số thì trả về 0
    }
}

int DoUuTien(string ToanTu)//hàm này dùng để trả về độ ưu tiên
{
    if(ToanTu=="+"||ToanTu=="-")//độ ưu tiên của + và - là 1
        return 1;
    else if(ToanTu=="*"||ToanTu=="/")//độ ưu tiên của * và / là 2
        return 2;
    else 
        return 0;
}

void ChuyenBaLan(string BieuThuc , stack<string>&mystack , queue<string>&myqueue)
{
    while(!BieuThuc.empty())
    {
        string temp=LayPhanTu(BieuThuc);
        if(KiemTraPhanTu(temp)==0)// là số thì push nó qua queue
        {
            myqueue.push(temp);
        }
        else
        {
            if(KiemTraPhanTu(temp) == 1)// là toán tử 
            {
                while(!mystack.empty())
                {
                    if(KiemTraPhanTu(mystack.top())==1 && DoUuTien(mystack.top()) >= DoUuTien(temp))//kiểm tra là toán tử và so sánh độ ưu tiên của 2 toán tử
                    {
                        myqueue.push(mystack.top());//đưa toán tử qua queue
                        mystack.pop();//loại bỏ toán tử khỏi stack
                    }
                    else
                        break;
                }
                mystack.push(temp);
            }
            else
            {
                if(temp=="(")//gặp dấu ngoặc mở thì push nó vào stack
                    mystack.push(temp);
                else
                {
                    if(temp==")")//gặp dấu ngoặc đóng
                    {
                        while(!mystack.empty())
                        {
                            if(mystack.top()!="(")//push toàn bộ stack qua queue cho đến khi gặp dấu ngoặc mở
                            {
                                myqueue.push(mystack.top());
                                mystack.pop();
                            }
                            else
                                break;
                        }
                    }
                    mystack.pop();//xóa dấu ngoặc mở luôn
                }
            }
        }
    }
    while(!mystack.empty())//chuyển những phần tử còn lại bên stack qua queue
    {
        myqueue.push(mystack.top());
        mystack.pop();
    }
}

double TinhToan(string dau,double a,double b)//hàm thực hiện tính toán
{
    if(dau=="+")
        return a+b;
    else if(dau=="-")
        return a-b;
    else if(dau=="*")
        return a*b;
    else if(dau=="/")
        return a/b;
    return 0; 
}

void KetQua(queue<string>&myqueue , stack<double>&mystack2)
{
    while(!myqueue.empty())
    {
        string temp=myqueue.front();//lấy ra phần tử của queue và xóa nó sau đó
        myqueue.pop();
        if(KiemTraPhanTu(temp)==0)// là số
        {
            mystack2.push(stof(temp));//thì push nó vào trong stack
        }
        else
        {
            if(mystack2.size()<2)//khi stack chỉ còn 1 phần tử thì ko thể thực hiện tính toán
            {
                cout<<"Bieu thuc ko hop le\n";
            }
            else//trường hợp còn lại chúng ta sẽ tiến hành tạo ra 2 biến num để lưu trữ giá trị số và thực hiện tính toán bên trong stack
            {
                double num1=mystack2.top();
                mystack2.pop();
                double num2=mystack2.top();
                mystack2.pop();
                double ketqua=TinhToan(temp,num2,num1);//luôn luôn phải lấy thằng 2 tính toán với thằng đầu nếu không biểu thức tính toán sẽ sai
                mystack2.push(ketqua);//sau khi tính toán thì đẩy kết quả vừa tính được vào lại trong stack
            }
        }
    }
    cout<<mystack2.top()<<endl;
              
}

void ChuanHoaChuoi(string &BieuThuc)//chuyển chuỗi về dạng ko còn khoảng trắng
{
    for(int i=0;i<BieuThuc.size();i++)
    {
        if(BieuThuc[i]==' ')
        {
            BieuThuc.erase(i,1);
        }
    }
}

void PhuongTrinhBac2(double a,double b,double c)
{
    double Delta=pow(b,2)-4*a*c;
    if(Delta<0)
        cout<<"Phuong trinh vo nghiem!!!\n";
    else if(Delta==0)
    {
        double x=(-b)/(2*a);
        cout<<"Phuong trinh co nghiem kep la:"<<x<<endl;
    }
    else
    {
        double x1=(-b+sqrt(Delta))/(2*a);
        double x2=(-b-sqrt(Delta))/(2*a);
        cout<<"Phuong trinh co 2 nghiem phan biet la:\n";
        cout<<"Nghiem 1:"<<x1<<endl;
        cout<<"Nghiem 2:"<<x2<<endl;
    }
}

void PhuongTrinhBac3(double a,double b,double c,double d)
{
    if(a==0)
    {
        cout<<"Phuong trinh vo nghiem\n";
        return;
    }
    double Delta=b*b-3*a*c;
    double k=0;
    if(Delta!=0)
    {
        double Tuk=9*a*b*c-2*pow(b,3)-27*a*a*d;
        double Mauk=2*sqrt(pow(fabs(Delta),3));
        k=Tuk/Mauk;
    }
    if(Delta>0)
    {
        if(fabs(k)<=1)
        {
            double x1=(2*sqrt(Delta)*cos(acos(k)/3)-b)/(3*a);
            double x2=(2*sqrt(Delta)*cos(acos(k)/3-(2*M_PI/3))-b)/(3*a);
            double x3=(2*sqrt(Delta)*cos(acos(k)/3+(2*M_PI/3))-b)/(3*a);
            cout<<"Phuong trinh co 3 nghiem lan luot la:\n";
            cout<<"Nghiem thu 1:"<<x1<<endl;
            cout<<"Nghiem thu 2:"<<x2<<endl;
            cout<<"Nghiem thu 3:"<<x3<<endl;
        }   
        else if(fabs(k)>1)
        {
            double Phan1=(sqrt(Delta)*fabs(k))/(3*a*k);
            double Phan2=pow((fabs(k)+sqrt(pow(k,2)-1)),1.0/3)+pow((fabs(k)-sqrt(pow(k,2)-1)),1.0/3);
            double Phan3=b/(3*a);
            double x=Phan1*Phan2-Phan3;
            cout<<"Phuong trinh co 1 nghiem duy nhat la:"<<x<<endl;
        }
    }
    else if(Delta==0)
    {
        double BieuThuc=pow(b,3)-27*a*a*d;
        if(BieuThuc==0)
        {
            double x=(-b)/(3*a);
            cout<<"Phuong trinh co 1 nghiem boi:"<<x<<endl;
        }
        else//Biểu thức khác 0
        {
            double x=(-b-pow(-pow(b,3)-27*a*a*d,1.0/3))/(3*b);//do hàm pow ko nhận số âm nên ta phải đổi công thức gốc
            cout<<"Phuong trinh co 1 nghiem duy nhat:"<<x<<endl;
        }
    }
    else
    {
        double Phan1=(sqrt(fabs(Delta)))/(3*a);
        double Phan2=pow((k+sqrt(k*k+1)),1.0/3)-pow(-(k-sqrt(k*k+1)),1.0/3);//do hàm pow ko nhận số âm nên ta phải đổi công thức gốc
        double Phan3=b/(3*a);
        double x=Phan1*Phan2-Phan3;
        cout<<"Phuong trinh co 1 nghiem duy nhat la:"<<x<<endl;
    }
}

int main()
{
    system("cls");
    menu:
    {
        system("cls");
        int chon;
        cout<<"Chao mung den voi may tinh thu gon\n";
        cout<<"1.Thuc hien tinh toan bieu thuc\n";
        cout<<"2.Tinh nghiem phuong trinh bac 2\n";
        cout<<"3.Tinh nghiem phuong trinh bac 3\n";
        cout<<"Nhap vao lua chon cua ban:";
        cin>>chon;
        switch(chon)
        {
            case 1:
                goto TinhToanBieuThuc;
            case 2:
                goto PhuongTrinhBac2;
            case 3:
                goto PhuongTrinhBac3;
            default:
            {
                cout<<"Nhap vao khong hop le!!!";
                goto menu;
            }
        }
    }

    yesno:
    {
        char v;
        cout<<"Nhan y de tiep tuc nhan bat ky de thoat:";
        cin>>v;
        if(v=='y')
            goto menu;
        else
            return 0;
    }

    TinhToanBieuThuc:
    {
        stack<string>mystack1;
        stack<double>mystack2;
        queue<string>myqueue;
        string BieuThuc;
        while(true)
        {
            cout<<"\n";
            fflush(stdin);
            cout<<"Nhap vao bieu thuc:";
            getline(cin,BieuThuc);
            if(BieuThuc=="q")
                break;
            ChuanHoaChuoi(BieuThuc);
            ChuyenBaLan(BieuThuc,mystack1,myqueue);
            KetQua(myqueue,mystack2);
        }
        goto yesno;
    }

    PhuongTrinhBac2:
    {
        cout<<"\n\n";
        double a,b,c;
        cout<<"Phuong trinh bac 2 co dang: ax^2 + bx + c =0\n";
        cout<<"Nhap vao a:";
        cin>>a;
        cout<<"Nhap vao b:";
        cin>>b;
        cout<<"Nhap vao c:";
        cin>>c;
        PhuongTrinhBac2(a,b,c);
        goto yesno;
    }

    PhuongTrinhBac3:
    {
        cout<<"\n\n";
        double a,b,c,d;
        cout<<"Phuong trinh bac 3 co dang: ax^3 + bx^2 + cx + d =0\n";
        cout<<"Nhap vao a:";
        cin>>a;
        cout<<"Nhap vao b:";
        cin>>b;
        cout<<"Nhap vao c:";
        cin>>c;
        cout<<"Nhap vao d:";
        cin>>d;
        PhuongTrinhBac3(a,b,c,d);
        goto yesno;
    }
}