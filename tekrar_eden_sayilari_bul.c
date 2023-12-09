#include <stdio.h>

typedef unsigned int  UINT32;
typedef char          UINT8;
typedef unsigned long UINT16;

#define DIZI_BOYUT (20U)

/************************************************
* Isim : Furkan Tuluk
* Tarih: 22/10/2023
* Aciklama: Bu fonksiyon bir liste icerisinde tekrar
			eden sayilarin bulunmasini saglamaktadir.
* @param1:[UINT16 *list_u16a] sayilarin bulundugu dizi.
* @param2:[UINT8   arr_len_u8] dizinin uzunlugu.
* not    :
* return :[void]
***********************************************/
void tekrar_eden_sayilari_bul(UINT32 *list_u32a, 
	                          UINT8   arr_len_u8)
{
	UINT16  new_list_u16a[DIZI_BOYUT] = { 0 };                 //!< tekrarlanan sayilarin eklenecegi liste
	UINT32 *baslangic_addr_u32 = list_u32a;            //!< dizinin baslangic adresinin alinmasi
	UINT16  sayac_u16 = 0;							   //!< for icinde dizinin uzunlugu kadar donecek sayac
	UINT8   tekrar_varmi_u8 = 0;					   //!< listenin icinde tekrar oldugu zaman kalkacak flag
	UINT16  new_list_index_u16 = 0;					   //!< tekrarlanan sayilar dizisinin indeksi
	UINT16  dongu_tekrar_u16 = 0;					   //!< dizinin her bir elemaninin tekrar kontrolu icin for dongusunu bastan yaptiran değişken
	UINT8   ilk_deger_u8 = 1;						   //!< her for dongusu tekrarinda sayac degerinin bir degerine esitlenmesini saglar.

	for (sayac_u16 = ilk_deger_u8; sayac_u16 < arr_len_u8; sayac_u16++)
	{
		if ((list_u32a[sayac_u16] == *baslangic_addr_u32))
		{
			tekrar_varmi_u8 = 1;
		}
		if (1 == tekrar_varmi_u8)
		{
			new_list_u16a[new_list_index_u16] = list_u32a[sayac_u16];
			sayac_u16++;
			new_list_index_u16++;
			tekrar_varmi_u8 = 0;

		}
		if ((dongu_tekrar_u16 < arr_len_u8) && (sayac_u16 == arr_len_u8 - 1))
		{
			dongu_tekrar_u16++;
			baslangic_addr_u32++;
			ilk_deger_u8++;
			sayac_u16 = ilk_deger_u8;
		}
	}
	//!< son indeks kontrolü yapilmadigi icin burada son indeks kontrolu yapilir.
	if (list_u32a[arr_len_u8 - 1] == list_u32a[arr_len_u8 - 2])
	{
		new_list_u16a[new_list_index_u16] = list_u32a[arr_len_u8 - 1];
	}

	int new_list_length = sizeof(new_list_u16a) / sizeof(new_list_u16a[0]);
	printf("tekrarlanan sayilar: ");

	for (int i = 0; i < new_list_length; i++)
	{
		if (new_list_u16a[i] != 0)
		{
			
			printf("%d, ", new_list_u16a[i]);
		}
	}
}


int main() {

	UINT32 list_u32a[] = {10,15,20,5,7,8,9,10,5,8,78,78};
	UINT8 arr_len_u8   = sizeof(list_u32a) / sizeof(list_u32a[0]);
	tekrar_eden_sayilari_bul(list_u32a , arr_len_u8);



	return 0;
}
