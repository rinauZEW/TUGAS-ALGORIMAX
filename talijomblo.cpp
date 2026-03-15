#include<iostream>
#include<string>
using namespace std;

struct mahasiswa{
    int NIU;
    float IPK;
    string nama;
    mahasiswa *next;
};

void insertDepan(mahasiswa *&head,string nama,int NIU,float IPK){

    mahasiswa *baru = new mahasiswa;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;

    baru->next = head;
    head = baru;
}

void insertBelakang(mahasiswa *&head,string nama,int NIU,float IPK){

    mahasiswa *baru = new mahasiswa;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;
    baru->next = NULL;

    if(head == NULL){
        head = baru;
        return;
    }

    mahasiswa *nodepelari = head;

    while(nodepelari->next != NULL){
        nodepelari = nodepelari->next;
    }

    nodepelari->next = baru;
}

void insertTengah(mahasiswa *&head,string nama,int NIU,float IPK,int posisi){

    if(head == NULL || posisi == 1){
        insertDepan(head,nama,NIU,IPK);
        return;
    }

    mahasiswa *baru = new mahasiswa;

    baru->nama = nama;
    baru->NIU = NIU;
    baru->IPK = IPK;

    mahasiswa *nodepelari= head;

    for(int i=1;i<posisi-1;i++){
        nodepelari = nodepelari->next;
    }

    baru->next = nodepelari->next;
    nodepelari-> next = baru;
}

void deleteDepan(mahasiswa *&head){

    if(head == NULL){
        cout<<"Data yang ingin anda hapus kosong"<<endl;
        return;
    }

    mahasiswa *hapus = head;

    head = head->next;

    delete hapus;
}

void deleteBelakang(mahasiswa *&head){

    if(head == NULL){
        cout<<"Data kosong"<<endl;
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    mahasiswa *nodepelari = head;

    while(nodepelari->next->next != NULL){
        nodepelari = nodepelari->next;
    }

    delete nodepelari->next;
    nodepelari->next = NULL;
}

void deleteTengah(mahasiswa *&head,int posisi){

    if(head == NULL){
        cout<<"Data kosong"<<endl;
        return;
    }

    mahasiswa *nodepelari = head;

    for(int i=1;i<posisi-1;i++){
        nodepelari = nodepelari->next;
    }

    mahasiswa *hapus = nodepelari->next;

    nodepelari->next = hapus->next;

    delete hapus;
}

void tampil(mahasiswa *head){

    if(head == NULL){
        cout<<"Belum ada data yang tersimpan -_-"<<endl;
        return;
    }

    mahasiswa *nodepelari = head;

    while(nodepelari != NULL){

        cout<<"\nNama : "<<nodepelari->nama<<endl;
        cout<<"NIU  : "<<nodepelari->NIU<<endl;
        cout<<"IPK  : "<<nodepelari->IPK<<endl;

        nodepelari = nodepelari->next;
    }
}

void cari(mahasiswa *head,string nama){

    mahasiswa *nodepelari = head;
    bool ketemu = false;

    while(nodepelari != NULL){

        if(nodepelari->nama == nama){

            cout<<"\nData ditemukan"<<endl;
            cout<<"Nama : "<<nodepelari->nama<<endl;
            cout<<"NIU  : "<<nodepelari->NIU<<endl;
            cout<<"IPK  : "<<nodepelari->IPK<<endl;

            ketemu = true;
        }

        nodepelari = nodepelari->next;
    }

    if(!ketemu){
        cout<<"Nama yang anda cari tidak ditemukan [] _ []"<<endl;
    }
}

int main(){

    mahasiswa *head = NULL;

    int pilihan,posisi;
    string nama;
    int NIU;
    float IPK;

    while(true){

        cout<<"\n<<<<<<FITUR>>>>>>>"<<endl;
        cout<<"1 Insert depan"<<endl;
        cout<<"2 Insert tengah"<<endl;
        cout<<"3 Insert belakang"<<endl;
        cout<<"4 Delete depan"<<endl;
        cout<<"5 Delete tengah"<<endl;
        cout<<"6 Delete belakang"<<endl;
        cout<<"7 Tampilkan data"<<endl;
        cout<<"8 Cari profil"<<endl;
        cout<<"9 Keluar"<<endl;

        cout<<"Pilih fitur : ";
        cin>>pilihan;

        if(cin.fail()){
         cin.clear();
         cin.ignore(1000,'\n');
         continue;
                     }

        if(pilihan>=1 && pilihan<=3){

            cout<<"Masukkan nama panggilan : ";
            cin>>nama;

            cout<<"Masukkan NIU : ";
            cin>>NIU;
             if(NIU>888888){
                cout<< " NIU yang anda masukkan salah *_*"<<endl;
             }
            cout<<"Masukkan IPK *gunakan tanda (.) untuk desimal : ";
            cin>>IPK;
            if(IPK<2){ 
                cout << "semangat IPK bukanlah akhir :)"<< endl;
            } else  if(IPK>3.8){
                cout<<"gila jenius iziin ketuaa"<<endl;
            }
        }

        if(pilihan==1){
            insertDepan(head,nama,NIU,IPK);
        }

        else if(pilihan==2){

            cout<<"Masukkan posisi : ";
            cin>>posisi;

            insertTengah(head,nama,NIU,IPK,posisi);
        }

        else if(pilihan==3){
            insertBelakang(head,nama,NIU,IPK);
        }

        else if(pilihan==4){
            deleteDepan(head);
        }

        else if(pilihan==5){

            cout<<"Masukkan posisi : ";
            cin>>posisi;

            deleteTengah(head,posisi);
        }

        else if(pilihan==6){
            deleteBelakang(head);
        }

        else if(pilihan==7){
            tampil(head);
        }

        else if(pilihan==8){

            cout<<"Masukkan nama yang anda cari '0_o' : ";
            cin>>nama;

            cari(head,nama);
        }

        else if(pilihan==9){
            break;
        }

    }

}