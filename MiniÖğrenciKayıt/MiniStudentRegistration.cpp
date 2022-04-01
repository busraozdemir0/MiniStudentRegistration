#include <iostream>
using namespace std;

class Ogrenci 
{
	private:
		string tc, ad, soyad, dersAdi;
		int yas, ortalama;
	public:
		 Ogrenci () { }
		
		//set metotlar� ile de�i�kenlerin de�erleri atand�.
		void setTc(string tc) { this->tc=tc; }
		void setAd(string ad) { this->ad=ad; }
		void setSoyad(string soyad) { this->soyad=soyad; }
		void setDersAdi(string dersAdi) { this->dersAdi=dersAdi; }
		void setYas(int yas) { this->yas=yas; }
		void setOrtalama(int ortalama) { this->ortalama=ortalama; }
		
		//get metotlar� ile bu de�erleri okuma i�lemi ger�ekle�tirilecek.
		string getTc() { return tc;	}
		string getAd() { return ad;	}
		string getSoyad() { return soyad;	}
		string getDersAdi() { return dersAdi;}
		int getYas() { return yas; }
		int getOrtalama() { return ortalama; }
		
		void Listele(Ogrenci []);
		
};


void Ogrenci::Listele(Ogrenci ogr[]) //Prototip s�n�f�n i�erisinde oldu�undan dolay� s�n�f d��ar�s�nda :: ile belirtilerek eri�ilir.
{
	for(int i=0;i<3;i++)
	{
		cout<<i+1<<". ogrenci bilgileri: "<<endl;
		cout<<"TC       : "<<ogr[i].getTc()<<endl;
		cout<<"AD       : "<<ogr[i].getAd()<<endl;
		cout<<"SOYAD    : "<<ogr[i].getSoyad()<<endl;
		cout<<"YAS      : "<<ogr[i].getYas()<<endl;
		cout<<"DERS ADI : "<<ogr[i].getDersAdi()<<endl;
		cout<<"ORTALAMA : "<<ogr[i].getOrtalama()<<endl;
		cout<<endl;
	}
	cout<<endl<<"Ogrenci bilgileri listelendi..."<<endl;
}


void Sirala(Ogrenci ogr[]) //Bilgileri isme g�re s�ralayacak olan fonksiyon
{
	system("cls"); //Ekran� temizlemek i�in
	
	Ogrenci temp;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(ogr[j].getAd().compare(ogr[j+1].getAd()) > 0 ) //Kendisinden sonra gelen isimden b�y�kse compare ile kar��la�t�rarak yer de�i�tirilecek.
			{
				temp=ogr[j];
				ogr[j]=ogr[j+1];
				ogr[j+1]=temp;
			}
		}	
	}
	cout<<endl<<"Liste siralandi"<<endl; 
	
	for(int i=0;i<3;i++)
	{
		cout<<i+1<<". ogrenci bilgileri: "<<endl;
		cout<<"TC       : "<<ogr[i].getTc()<<endl;
		cout<<"AD       : "<<ogr[i].getAd()<<endl;
		cout<<"SOYAD    : "<<ogr[i].getSoyad()<<endl;
		cout<<"YAS      : "<<ogr[i].getYas()<<endl;
		cout<<"DERS ADI : "<<ogr[i].getDersAdi()<<endl;
		cout<<"ORTALAMA : "<<ogr[i].getOrtalama()<<endl;
		cout<<endl;
	}
	cout<<endl<<"Ogrenci bilgileri listelendi..."<<endl;
}


void Ara(Ogrenci ogr[])
{
	bool sonuc=false;
	string aranan;
	Ogrenci temp;
	cout<<"Aradiginiz ogrencinin ismi: "; cin>>aranan; cout<<endl;
	for(int i=0;i<3;i++)
	{
		if(ogr[i].getAd().compare(aranan) == 0) //Aranan ��renci bulunur.
		{
			temp=ogr[i];
			sonuc=true;
			break;		
		}	
	}
	if (sonuc)
	{
		cout<<aranan<<" ismiyle aradiginiz ogrenci bilgileri: "<<endl ; 
		cout<<"TC       : "<<temp.getTc()<<endl;
		cout<<"AD       : "<<temp.getAd()<<endl;
		cout<<"SOYAD    : "<<temp.getSoyad()<<endl;
		cout<<"YAS      : "<<temp.getYas()<<endl;
		cout<<"DERS ADI : "<<temp.getDersAdi()<<endl;
		cout<<"ORTALAMA : "<<temp.getOrtalama()<<endl;
		cout<<endl;
	}
	else
	cout<<aranan<<" ismiyle aradiginiz ogrenci listede yok!"<<endl ;        
}


void enYuksekOrtalama(Ogrenci ogr[])
{
	int ortalama=0;
	Ogrenci temp;
	for(int i=0;i<3;i++)
	{
		if(ortalama < ogr[i].getOrtalama()) //Ortalamalar kar��la�t�r�larak en y�ksek ortalama bulunur.
		{
			temp=ogr[i];
			ortalama=ogr[i].getOrtalama();		
		}	
	}
        cout<<"En yuksek ortalamaya sahip olan ogrenci bilgileri: "<<endl ; 
		cout<<"TC       : "<<temp.getTc()<<endl;
		cout<<"AD       : "<<temp.getAd()<<endl;
		cout<<"SOYAD    : "<<temp.getSoyad()<<endl;
		cout<<"YAS      : "<<temp.getYas()<<endl;
		cout<<"DERS ADI : "<<temp.getDersAdi()<<endl;
		cout<<"ORTALAMA : "<<temp.getOrtalama()<<endl;
		cout<<endl;
}


int main()
{
	Ogrenci ogr[3];
	string tc, ad, soyad, dersAdi;
	int yas, ortalama;
	
	for(int i=0;i<3; i++)
	{
		cout<<i+1<<". ogrenci bilgilerini giriniz: "<<endl;
		cout<<"TC       : ";   cin>>tc;
		cout<<"AD       : ";   cin>>ad;
		cout<<"SOYAD    : ";   cin>>soyad;
		cout<<"YAS      : ";   cin>>yas;
		cout<<"DERS ADI : ";   cin>>dersAdi;
		cout<<"ORTALAMA : ";   cin>>ortalama;
		
		ogr[i].setTc(tc);
		ogr[i].setAd(ad);
		ogr[i].setSoyad(soyad);
		ogr[i].setYas(yas);
		ogr[i].setDersAdi(dersAdi);
		ogr[i].setOrtalama(ortalama);		
		
		cout<<endl;
	}
	cout<<"Kayit islemi tamamlandi..."<<endl<<"Girilen bilgiler listeleniyor..."<<endl;
	
	ogr[0].Listele(ogr); //Diziyi parametre olarak listele metoduna g�nderdik.
	
	cout<<endl;
	Sirala(ogr); //Sirala fonksiyonu s�n�ftan ba��ms�z oldu�u i�in Listele fonkriyonu gibi ogr[0] �eklinde g�ndermemize gerek yok.	
	cout<<endl;
	
	Ara(ogr);
	cout<<endl;
	
	enYuksekOrtalama(ogr);
		
	return 0;
}
