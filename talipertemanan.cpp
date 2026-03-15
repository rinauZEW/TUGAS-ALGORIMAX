#include<iostream>
#include<string>
using namespace std;

struct mahasiswa{
    string nama;
    int NIU;
    float IPK;
    mahasiswa *next;
};

mahasiswa *head = NULL;

void insertKosong(string nama,int NIU,float IPK){

    mahasiswa *baru = new mahasiswa;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;

    head = baru;
    baru->next = head;
}

void insertDepan(string nama,int NIU,float IPK){

    if(head == NULL){
        insertKosong(nama,NIU,IPK);
        return;
    }

    mahasiswa *baru = new mahasiswa;
    mahasiswa *cur = head;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;

    while(cur->next != head){
        cur = cur->next;
    }

    baru->next = head;
    cur->next = baru;
    head = baru;
}

void insertBelakang(string nama,int NIU,float IPK){

    if(head == NULL){
        insertKosong(nama,NIU,IPK);
        return;
    }

    mahasiswa *baru = new mahasiswa;
    mahasiswa *cur = head;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;

    while(cur->next != head){
        cur = cur->next;
    }

    cur->next = baru;
    baru->next = head;
}

void insertTengah(string nama,int NIU,float IPK,int posisi){

    if(head == NULL || posisi == 1){
        insertDepan(nama,NIU,IPK);
        return;
    }

    mahasiswa *baru = new mahasiswa;
    mahasiswa *cur = head;
    mahasiswa *prev = NULL;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;

    for(int i=1;i<posisi;i++){
        prev = cur;
        cur = cur->next;
    }

    prev->next = baru;
    baru->next = cur;
}

void deleteDepan(){

    if(head == NULL){
        cout<<" Maaf List kosong !!! silahkan isi data telebih dahulu (-_+)"<<endl;
        return;
    }

    mahasiswa *cur = head;
    mahasiswa *hapus = head;

    while(cur->next != head){
        cur = cur->next;
    }

    head = head->next;
    cur->next = head;

    delete hapus;
}

void deleteBelakang(){

    if(head == NULL){
        cout<<"Maaf List kosong!!!! apakah anda lupa mengisi ??"<<endl;
        return;
    }

    mahasiswa *cur = head;
    mahasiswa *prev = NULL;

    while(cur->next != head){
        prev = cur;
        cur = cur->next;
    }

    prev->next = head;

    delete cur;
}

void deleteTengah(int posisi){

    mahasiswa *cur = head;
    mahasiswa *prev = NULL;

    for(int i=1;i<posisi;i++){
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;

    delete cur;
}

void tampil(){

    if(head == NULL){
        cout<<"Data sekarang sedang kosong(hah kosong astaugfirullah)"<<endl;
        return;
    }

    mahasiswa *cur = head;

    do{

        cout<<"\nNama : "<<cur->nama<<endl;
        cout<<"NIU  : "<<cur->NIU<<endl;
        cout<<"IPK  : "<<cur->IPK<<endl;

        cur = cur->next;

    }while(cur != head);
}

int main(){

    int pilihan,posisi;
    string nama;
    int NIU;
    float IPK;

    while(true){

        cout<<"\n<<<<<<<<<< Fitur >>>>>>>>>"<<endl;
        cout<<"1 Insert depan"<<endl;
        cout<<"2 Insert tengah"<<endl;
        cout<<"3 Insert belakang"<<endl;
        cout<<"4 Delete depan"<<endl;
        cout<<"5 Delete tengah"<<endl;
        cout<<"6 Delete belakang"<<endl;
        cout<<"7 Tampilkan data"<<endl;
        cout<<"8 Keluar"<<endl;

        cout<<" ayo Pilih fitur dengan ketik no  : ";
        cin>>pilihan;

        if(pilihan>=1 && pilihan<=3){

            cout<<"Nama : ";
            cin>>nama;

            cout<<"NIU : ";
            cin>>NIU;

            cout<<"IPK : ";
            cin>>IPK;
            if(IPK<2){
                cout << " ganbare :)"<< endl;
            } else if( IPK> 3.8){
                cout << " hai tuan pintar senang bisa bernemu " << endl;
            }
        }

        if(pilihan==1)
            insertDepan(nama,NIU,IPK);

        else if(pilihan==2){
            cout<<"Posisi : ";
            cin>>posisi;
            insertTengah(nama,NIU,IPK,posisi);
        }

        else if(pilihan==3)
            insertBelakang(nama,NIU,IPK);

        else if(pilihan==4)
            deleteDepan();

        else if(pilihan==5){
            cout<<" pilih Posisi yang kalian mau  : ";
            cin>>posisi;
            deleteTengah(posisi);
        }

        else if(pilihan==6)
            deleteBelakang();

        else if(pilihan==7)
            tampil();

        else if(pilihan==8)
            break;
    }

}