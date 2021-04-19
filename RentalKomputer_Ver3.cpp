#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
	float jam;
	float menit;
	float detik;	
} Time;

typedef struct {
	int tanggal;
	int bulan;
	int tahun;
} Date;

typedef struct {
	int noKomputer;
	Date tanggalMasuk;
	Time jamMasuk;
	Date tanggalKeluar;
	Time jamKeluar;
	float biayaTotal;
} Pengguna;
Pengguna dataWarnet[11];

void ShowStatusKomputer (Pengguna dataWarnet[11]); // Procedure
	// Author : Bryan Azriel Parulian
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 26 Desember 2019
		// "Mengubah seluruh tampilan Menu Status Komputer dengan penambahan Online / Offline supaya lebih transparan dan juga dapat melihat data dari setiap komputer"
bool Validasi (int noKomp, const char ket[6], Pengguna dataWarnet[11]); // Function
	// Author : Akmal Rishad Pratama
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 26 Desember 2019
		// "Merombak secara keseluruhan yang dulunya banyak function Validasi menjadi 1 function Validasi dengan keterangan yang berbeda"
int PerhitunganTahunKabisat (int noKomp, const char ket[10], Pengguna dataWarnet[11]); // Function
	// Author : 
	// Terakhir Dibuat : 26 Desember 2019
	// Terakhir Diupdate : -
void Login (int noKomp, Pengguna dataWarnet[11]); // Procedure
	// Author : Bryan Azriel Parulian
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 25 Desember 2019
		// "Perubahan cara memanggil function Validasi yaitu langsung di kondisi if, menambahkan entry data Tanggal Masuk beserta Validasinya, kemudian menambahkan procedure RecapDataFile"
void Logout (int noKomp, Pengguna dataWarnet[11]); // Procedure
	// Author : Bryan Azriel Parulian
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 25 Desember 2019
		// Perubahan cara memanggil function Validasi yaitu langsung di kondisi if, Menambahkan entry data Tanggal Keluar beserta Validasinya, kemudian menambahkan procedure RecapDataFile"
void PerhitunganBiaya (int noKomp, Pengguna dataWarnet[11]); // Procedure
	// Author : Athiyya Rahmawati
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 26 Desember 2019
		// "Menghapus function BiayaPrinter dan BiayaTotal, proses function tersebut langsung di tuliskan di procedure Perhitungan Biaya supaya lebih efektif"
float BiayaRental (int noKomp, Pengguna dataWarnet[11]); // Function
	// Author : Athiyya Rahmawati
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : -
float PerhitunganDurasiJam (int noKomp, Pengguna dataWarnet[11]); // Function
	// Author : Bryan Azriel Parulian
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 26 Desember 2019
		// "Menambahkan kondisi bilamana durasi yang telah dihitung hasilnya negatif (dengan cara 24 jam + hasil tersebut)"
float PerhitunganDurasiHari (int noKomp, Pengguna dataWarnet[11]); // Function
	// Author :
	// Terakhir Dibuat : 26 Desember 2019
	// Terakhir Diupdate : -
float BiayaMakanan (int pesanan, int porsi); // Function
	// Author : Athiyya Rahmawati
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : -
void ResetKomp (int noKomp, Pengguna dataWarnet[11]); // Procedure
	// Author : Akmal Rishad Pratama
	// Terakhir Dibuat : 8 Desember 2019
	// Terakhir Diupdate : 25 Desember 2019
		// "Menambahkan reset Tanggal Masuk dan Keluar serta Biaya Total dari array dataWarnet"
void RecapDataFile (int noKomp, const char ket[20], Pengguna dataWarnet[11]); // Procedure
	// Author :
	// Terakhir Dibuat : 25 Desember 2019
	// Terakhir Diupdate : 27 Desember 2019
		// "Merapihkan tampilan pada struk (Looping blank space-nya)"
void CetakStruk (int noKomp, float biayaPrinter, float biayaMakanan, Pengguna dataWarnet[11]); // Procedure
	// Author : 
	// Terakhir Dibuat : 26 Desember 2019
	// Terakhir Diupdate : 27 Desember 2019
		// "Merapihkan tampilan Waktu Masuk dan Keluar pada struk (Looping blank space-nya)"
int HitungDigit (float biaya); // Function
	// Author : 
	// Terakhir Dibuat : 26 Desember 2019
	// Terakhir Diupdate : -
void SetColor (int ForgC); // Prosedure
	// Author or Source Code: "https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks"

main () {
	RecapDataFile (1, "ReadData", dataWarnet);
	SetColor(15);
		
	for (;;) { // Looping Forever
		int menu;
		int noKomp;
		char loop[1];
		
		system ("cls");
		printf ("======================================================\n");
		SetColor(3);
		printf ("\t\t      MASTER.NET\n");
		printf ("      Jl.Pesantren No.115, Cibabat, Cimahi Utara\n");
		SetColor(15); 
		printf ("======================================================\n");
		printf ("  1. Login\n");
		printf ("  2. Logout\n");
		printf ("  3. Menampilkan History Penggunaan Rental\n");
		printf ("  4. Informasi Tentang Program\n");
		printf ("  5. Keluar\n");
		printf ("======================================================\n");
		printf (" Input menu: ");
		scanf ("%d", &menu);
		switch (menu) {
			case 1 :
				system ("cls");
				printf ("======================================================\n");
				for (int i = 1; i <= 18; i++) {
					printf (" ");
				}
				printf ("=== MENU LOGIN ===\n");
				ShowStatusKomputer (dataWarnet);
				Login (noKomp, dataWarnet);
				break;
			case 2 :
				system ("cls");
				printf ("======================================================\n");
				for (int i = 1; i <= 18; i++) {
					printf (" ");
				}
				printf ("=== MENU LOGOUT ===\n");
				ShowStatusKomputer (dataWarnet);
				Logout (noKomp, dataWarnet);
				break;
			case 3 :
				system ("cls");
				printf ("======================================================\n");
				for (int i = 1; i <= 11; i++) {
					printf (" ");
				}
				printf ("=== HISTORY PENGGUNA RENTAL ===\n\n");
				printf ("|---------------------------------------------------------------------------------|\n");
				printf ("|  No.Komp\t     Tanggal\t\t\t   Waktu\t     Total Biaya  |\n");
				printf ("|---------------------------------------------------------------------------------|\n");
				RecapDataFile (0, "ReadRecap", dataWarnet);
				break;
			case 4 :
				system ("cls");
				printf ("=====================================================\n");
				for (int i = 1; i <= 14; i++) {
					printf (" ");
				}
				printf ("=== INFORMASI PROGRAM ===\n\n");
				RecapDataFile (0, "ReadInfo", dataWarnet);
				printf ("\n");
				break;
			case 5 :
				exit (0);
				break;
			default :
				printf ("Inputan tidak benar!");
				exit (0);
				break;
		}
		
		printf ("======================================================\n");
		printf ("Tekan 'Enter' untuk kembali.");
		gets (loop);
		gets (loop);	
	}	
}

void ShowStatusKomputer (Pengguna dataWarnet[11]) {
	int menu;
	int noKomp;
	
	printf("\n|\t1\t|\t2\t|\t3\t|\t4\t|\t 5\t |\n");
	for (noKomp = 1; noKomp <= 4; noKomp++) {						
		if (Validasi (noKomp, "Komp", dataWarnet) == true) {
			SetColor(15); printf ("|    ");
			SetColor(4); printf ("Offline    "); 
		}
		
		else {
			SetColor(15); printf ("|    ");
			SetColor(2); printf (" Online    ");
		}
	}
	
	if (Validasi (5, "Komp", dataWarnet) == true) {
		SetColor(15); printf ("|    ");
		SetColor(4); printf (" Offline    ");  
	}
	
	else {
		SetColor(15); printf ("|     ");
		SetColor(2); printf ("Online     ");
	}
	
	SetColor(15);
	printf ("|\n");
	printf ("----------------------------------------------------------------------------------");
	printf("\n|\t6\t|\t7\t|\t8\t|\t9\t|       10\t |\n");
	
	for (noKomp = 6; noKomp <= 9; noKomp++) {
		if (Validasi (noKomp, "Komp", dataWarnet) == true) {
			SetColor(15); printf ("|    ");
			SetColor(4); printf ("Offline    ");  
		}
		
		else {
			SetColor(15); printf ("|    ");
			SetColor(2); printf (" Online    ");
		}
	}
	
	if (Validasi (10, "Komp", dataWarnet) == true) {
		SetColor(15); printf ("|    ");
		SetColor(4); printf (" Offline    ");  
	}
	
	else {
		SetColor(15); printf ("|     ");
		SetColor(2); printf ("Online     ");
	}
	
	SetColor(15);
	printf ("|\n\n");
}

bool Validasi (int noKomp, const char ket[15], Pengguna dataWarnet[11]) {
	bool validasi;
	if (strcmp (ket, "Komp") == 0) {
		if ((dataWarnet[noKomp].jamMasuk.jam == 0) && (dataWarnet[noKomp].jamMasuk.menit == 0) && (dataWarnet[noKomp].jamMasuk.detik == 0)) {
			validasi = true;
		}
		else {
			validasi = false;
		}	
	}
	
	if (strcmp (ket, "TanggalMasuk") == 0) {
		int jumlahHari;
		if (
			(dataWarnet[noKomp].tanggalMasuk.tanggal > 0) && 
			(dataWarnet[noKomp].tanggalMasuk.bulan > 0) && 
			(dataWarnet[noKomp].tanggalMasuk.bulan <= 12) && 
			(dataWarnet[noKomp].tanggalMasuk.tahun > 0)
		) {
			if (dataWarnet[noKomp].tanggalMasuk.tanggal <= PerhitunganTahunKabisat (noKomp, "BulanMasuk", dataWarnet)){
				validasi = true;
			}
			
			else {
				validasi = false;
			}
		}
		
		else {
			validasi = false;
		}
	}
	
	if (strcmp (ket, "TanggalKeluar") == 0) {
		int jumlahHari;
		if (
			(dataWarnet[noKomp].tanggalKeluar.tanggal > 0) && 
			(dataWarnet[noKomp].tanggalKeluar.bulan > 0) && 
			(dataWarnet[noKomp].tanggalKeluar.bulan <= 12) && 
			(dataWarnet[noKomp].tanggalKeluar.tahun > 0)
		) {
			if ((dataWarnet[noKomp].tanggalKeluar.tanggal <= PerhitunganTahunKabisat (noKomp, "BulanKeluar", dataWarnet)) && (PerhitunganDurasiHari (noKomp, dataWarnet) >= 0)) {
				validasi = true;
			}
			
			else {
				validasi = false;
			}
		}
		
		else {
			validasi = false;
		}
	}
	
	if (strcmp (ket, "JamMasuk") == 0) {
		if (
			(
				(dataWarnet[noKomp].jamMasuk.jam >= 0) && 
				(dataWarnet[noKomp].jamMasuk.jam <= 24)
			) && 
			(
				(dataWarnet[noKomp].jamMasuk.menit >= 0) && 
				(dataWarnet[noKomp].jamMasuk.menit <= 60)
			) && 
			(
				(dataWarnet[noKomp].jamMasuk.detik >= 0) && 
				(dataWarnet[noKomp].jamMasuk.detik <= 60)
			)
		) {
			validasi = true;
			if (dataWarnet[noKomp].jamMasuk.jam == 24) {
				if ((dataWarnet[noKomp].jamMasuk.menit == 0) && (dataWarnet[noKomp].jamMasuk.detik == 0)) {
					validasi = true;
				}
				
				else {
					validasi = false;
				}
			}
		}
	
		else {
			validasi = false;
		}
	}
	
	if (strcmp (ket, "JamKeluar") == 0) {
		if (
			(dataWarnet[noKomp].jamKeluar.jam >= 0) && 
			(dataWarnet[noKomp].jamKeluar.jam <= 24) && 
			(
				(dataWarnet[noKomp].jamKeluar.menit >= 0) && 
				(dataWarnet[noKomp].jamKeluar.menit <= 60)
			) && 
			(
				(dataWarnet[noKomp].jamKeluar.detik >= 0) && 
				(dataWarnet[noKomp].jamKeluar.detik <= 60)
			) && 
			(PerhitunganDurasiJam (noKomp, dataWarnet) >= 0)
		) {
			validasi = true;
			if ((PerhitunganDurasiJam (noKomp, dataWarnet) == 0) && (PerhitunganDurasiHari (noKomp, dataWarnet) == 0)) {
				validasi = false;
			}
			if (dataWarnet[noKomp].jamKeluar.jam == 24) {
				if ((dataWarnet[noKomp].jamKeluar.menit == 0) && (dataWarnet[noKomp].jamKeluar.detik == 0)) {
					validasi = true;
				}
				
				else {
					validasi = false;
				}
			}
		}
	
		else {
			validasi = false;
		}
	}
	return validasi;
}

int PerhitunganTahunKabisat (int noKomp, const char ket[15], Pengguna dataWarnet[11]) {
	int jumlahHari;
	if (strcmp (ket, "BulanMasuk") == 0) {	
		switch (dataWarnet[noKomp].tanggalMasuk.bulan) {
			case 2 : 
				if (
						(dataWarnet[noKomp].tanggalMasuk.tahun % 400 == 0) || 
					(
						(dataWarnet[noKomp].tanggalMasuk.tahun % 400 != 0) && 
						(dataWarnet[noKomp].tanggalMasuk.tahun % 100 != 0) && 
						(dataWarnet[noKomp].tanggalMasuk.tahun % 4 == 0)
					)
				) {
					jumlahHari = 29;
				}
				
				else {
					jumlahHari = 28;
				}
				break;
			case 6 :
				jumlahHari = 30;
				break;
			case 9 :
				jumlahHari = 30;
				break;
			case 11 :
				jumlahHari = 30;
				break;
			default :
				jumlahHari = 31;
				break;
		}
	}
	
	if (strcmp (ket, "BulanKeluar") == 0) {
		switch (dataWarnet[noKomp].tanggalKeluar.bulan) {
			case 2 : 
				if (
						(dataWarnet[noKomp].tanggalKeluar.tahun % 400 == 0) || 
					(	
						(dataWarnet[noKomp].tanggalKeluar.tahun % 400 != 0) && 
						(dataWarnet[noKomp].tanggalKeluar.tahun % 100 != 0) && 
						(dataWarnet[noKomp].tanggalKeluar.tahun % 4 == 0)
					)
				) {
					jumlahHari = 29;
				}
				
				else {
					jumlahHari = 28;
				}
				break;
			case 6 :
				jumlahHari = 30;
				break;
			case 9 :
				jumlahHari = 30;
				break;
			case 11 :
				jumlahHari = 30;
				break;
			default :
				jumlahHari = 31;
				break;
		}
	}
	
	if (strcmp (ket, "TahunMasuk") == 0) {
		if (
			(dataWarnet[noKomp].tanggalMasuk.tahun % 400 == 0) || 
			(
				(dataWarnet[noKomp].tanggalMasuk.tahun % 400 != 0) && 
				(dataWarnet[noKomp].tanggalMasuk.tahun % 100 != 0) && 
				(dataWarnet[noKomp].tanggalMasuk.tahun % 4 == 0)
			)
		) {
			jumlahHari = 364;
		}
			
		else {
			jumlahHari = 365;
		}
	}
	
	if (strcmp (ket, "TahunKeluar") == 0) {
		if (
			(dataWarnet[noKomp].tanggalKeluar.tahun % 400 == 0) || 
			(
				(dataWarnet[noKomp].tanggalKeluar.tahun % 400 != 0) && 
				(dataWarnet[noKomp].tanggalKeluar.tahun % 100 != 0) && 
				(dataWarnet[noKomp].tanggalKeluar.tahun % 4 == 0)
			)
		) {
			jumlahHari = 364;
		}
		
		else {
			jumlahHari = 365;
		}
	}
	return jumlahHari;
}

void Login (int noKomp, Pengguna dataWarnet[11]) {
	printf ("======================================================\n");
	printf ("Input No.Komputer : ");
	scanf ("%d", &noKomp);
	if ((noKomp >= 1) && (noKomp <= 10)) {
		if (Validasi (noKomp, "Komp", dataWarnet) == true) {
			printf ("Input Tanggal Masuk (Tanggal/Bulan/Tahun) : ");
			scanf ("%d/%d/%d", &dataWarnet[noKomp].tanggalMasuk.tanggal, &dataWarnet[noKomp].tanggalMasuk.bulan, &dataWarnet[noKomp].tanggalMasuk.tahun);
			if (Validasi (noKomp, "TanggalMasuk", dataWarnet) == true) {
				printf ("Input Jam Masuk (Jam:Menit:Detik) : ");
				scanf ("%f:%f:%f", &dataWarnet[noKomp].jamMasuk.jam, &dataWarnet[noKomp].jamMasuk.menit, &dataWarnet[noKomp].jamMasuk.detik);
					if (Validasi (noKomp, "JamMasuk", dataWarnet) == true) {
						printf ("Login berhasil!\n");
						RecapDataFile (noKomp, "WriteData", dataWarnet);	
					}
		
					else {
						printf ("Login tidak berhasil! Ada kesalahan pada pengisian Jam Masuk\n");
						dataWarnet[noKomp].tanggalMasuk.tanggal = 0;
						dataWarnet[noKomp].tanggalMasuk.bulan = 0;
						dataWarnet[noKomp].tanggalMasuk.tahun = 0;
						dataWarnet[noKomp].jamMasuk.jam = 0;
						dataWarnet[noKomp].jamMasuk.menit = 0;
						dataWarnet[noKomp].jamMasuk.detik = 0;
					}	
		}
	
			else {
				printf ("Login tidak berhasil! Ada kesalahan pada pengisian Tanggal Masuk\n");
				dataWarnet[noKomp].tanggalMasuk.tanggal = 0;
				dataWarnet[noKomp].tanggalMasuk.bulan = 0;
				dataWarnet[noKomp].tanggalMasuk.tahun = 0;
			}	
		}
		
		else {
			printf ("Komputer sedang digunakan\n");
			printf ("Login: Tanggal ");
			SetColor(2); printf ("%d/%d/%d\n", dataWarnet[noKomp].tanggalMasuk.tanggal, dataWarnet[noKomp].tanggalMasuk.bulan, dataWarnet[noKomp].tanggalMasuk.tahun);
			SetColor(15); printf ("       Jam     ");
			SetColor(2); printf ("%2.0f:%2.0f:%2.0f\n", dataWarnet[noKomp].jamMasuk.jam, dataWarnet[noKomp].jamMasuk.menit, dataWarnet[noKomp].jamMasuk.detik);
			SetColor(15);
			printf ("Carilah komputer yang tersedia / tidak digunakan\n");
		}
	}
	
	else {
		printf ("Hanya terdapat 10 Komputer di Warnet ini!\n");
	}
}

void Logout (int noKomp, Pengguna dataWarnet[11]) {
	printf ("======================================================\n");
	printf ("Input No.Komputer : ");
	scanf ("%d", &noKomp);
	if ((noKomp >= 1) && (noKomp <= 10)) {
		if (Validasi (noKomp, "Komp", dataWarnet) == false) {
			printf ("Input Tanggal Keluar (Tanggal/Bulan/Tahun) : ");
			scanf ("%d/%d/%d", &dataWarnet[noKomp].tanggalKeluar.tanggal, &dataWarnet[noKomp].tanggalKeluar.bulan, &dataWarnet[noKomp].tanggalKeluar.tahun);
			if (Validasi (noKomp, "TanggalKeluar", dataWarnet) == true) {
				printf ("Input Jam Keluar (Jam:Menit:Detik) : ");
				scanf ("%f:%f:%f", &dataWarnet[noKomp].jamKeluar.jam, &dataWarnet[noKomp].jamKeluar.menit, &dataWarnet[noKomp].jamKeluar.detik);
				if (Validasi (noKomp, "JamKeluar", dataWarnet) == true) {
					PerhitunganBiaya (noKomp, dataWarnet);
					RecapDataFile (noKomp, "AppendRecap", dataWarnet);
					ResetKomp (noKomp, dataWarnet);
					RecapDataFile (noKomp, "WriteData", dataWarnet);
				}
		
				else {
					printf ("Logout tidak berhasil! Ada kesalahan pada pengisian Jam Keluar\n");
					dataWarnet[noKomp].tanggalKeluar.tanggal = 0;
					dataWarnet[noKomp].tanggalKeluar.bulan = 0;
					dataWarnet[noKomp].tanggalKeluar.tahun = 0;
					dataWarnet[noKomp].jamKeluar.jam = 0;
					dataWarnet[noKomp].jamKeluar.menit = 0;
					dataWarnet[noKomp].jamKeluar.detik = 0;
				}
			}
	
			else {
				printf ("Logout tidak berhasil! Ada kesalahan pada pengisian Tanggal Keluar\n");
				dataWarnet[noKomp].tanggalKeluar.tanggal = 0;
				dataWarnet[noKomp].tanggalKeluar.bulan = 0;
				dataWarnet[noKomp].tanggalKeluar.tahun = 0;
			}
		}
				
		else {
			printf ("Komputer sedang tidak digunakan\n");
		}
	}
				
	else {
		printf ("Hanya terdapat 10 Komputer di Warnet ini!\n");
	}
}

void PerhitunganBiaya (int noKomp, Pengguna dataWarnet[11]) {
	float biayaPrinter = 0;
	float biayaMakanan = 0;
	int kertasBerwarna, kertasTdkBerwarna, pesanan, porsi, menu;
	
	printf ("=====================================================\n");
	printf ("Apakah menggunakan printer? (Yes = 1 / No = 0)\n");
	printf ("  > ");
	scanf ("%d", &menu);
	if (menu == 1) {
		printf ("Berapa jumlah kertas yang dicetak hitam putih? (1 = Rp.500)\n");
		printf ("  > ");
		scanf ("%d", &kertasTdkBerwarna);
		printf ("Berapa jumlah kertas yang dicetak berwarna? (1 = Rp.1000)\n");
		printf ("  > ");
		scanf ("%d", &kertasBerwarna);
		biayaPrinter = (kertasTdkBerwarna * 500) + (kertasBerwarna * 1000);
	}
	
	printf ("=====================================================\n");
	printf ("Apakah membeli makanan atau minuman? (Yes = 1 / No = 0)\n");
	printf ("  > ");
	scanf ("%d", &menu);
	printf ("=====================================================\n");
	if (menu == 1) {
		do {
			printf ("    1. Mie Instan Goreng  (Rp.5000)\n");
			printf ("    2. Mie Instan Rebus\t  (Rp.5000)\n");
			printf ("    3. Nasi Goreng\t  (Rp.10000)\n");
			printf ("    4. Sosis Goreng\t  (Rp.3000)\n");
			printf ("    5. Kopi\t\t  (Rp.3000)\n");
			printf ("    6. Air Putih\t  (Rp.2500)\n");
			printf ("    7. Teh\t\t  (Rp.3000)\n");
			printf ("Input menu : ");
			scanf ("%d", &pesanan);
			printf ("Berapa porsi / gelas yang dibeli?\n");
			printf ("  > ");
			scanf ("%d", &porsi);
			biayaMakanan = biayaMakanan + BiayaMakanan (pesanan, porsi);
			printf ("Apakah membeli makanan atau minuman lagi? (Yes = 1 / No = 0)\n");
			printf ("  > ");
			scanf ("%d", &menu);
			printf ("=====================================================\n");
		} while (menu == 1);
	}
	dataWarnet[noKomp].biayaTotal = BiayaRental (noKomp, dataWarnet) + biayaPrinter + biayaMakanan;
	CetakStruk (noKomp, biayaPrinter, biayaMakanan, dataWarnet);
}

float BiayaRental (int noKomp, Pengguna dataWarnet[11]) {
	float biayaRental;
	if (PerhitunganDurasiHari (noKomp, dataWarnet) == 0) {
		biayaRental = PerhitunganDurasiJam (noKomp, dataWarnet) * 3000;
	}
	
	if (PerhitunganDurasiHari (noKomp, dataWarnet) > 0) {
		biayaRental = (PerhitunganDurasiJam (noKomp, dataWarnet) + ((PerhitunganDurasiHari (noKomp, dataWarnet) - 1) * 24)) * 3000;
	}
	
	if (biayaRental > 10000) {
		biayaRental = biayaRental - 1000;
	}
	return biayaRental;
}

float PerhitunganDurasiJam (int noKomp, Pengguna dataWarnet[11]) {
	float durasi;
	if (PerhitunganDurasiHari (noKomp, dataWarnet) == 0) {
		durasi = (
			(
				(dataWarnet[noKomp].jamKeluar.jam * 3600) + 
				(dataWarnet[noKomp].jamKeluar.menit * 60) + 
				(dataWarnet[noKomp].jamKeluar.detik)
			) - 
			(
				(dataWarnet[noKomp].jamMasuk.jam * 3600) + 
				(dataWarnet[noKomp].jamMasuk.menit * 60) + 
				(dataWarnet[noKomp].jamMasuk.detik)
			)
		) / 3600;	
	}
	
	if (PerhitunganDurasiHari (noKomp, dataWarnet) > 0) {
		durasi = (
			(
				(dataWarnet[noKomp].jamKeluar.jam * 3600) + 
				(dataWarnet[noKomp].jamKeluar.menit * 60) + 
				(dataWarnet[noKomp].jamKeluar.detik)
			) - 
			(
				(dataWarnet[noKomp].jamMasuk.jam * 3600) + 
				(dataWarnet[noKomp].jamMasuk.menit * 60) + 
				(dataWarnet[noKomp].jamMasuk.detik)
			)
		) / 3600;
		if (durasi < 0) {
			durasi = 24 + durasi;	
		}
	}
	return durasi;
}

float PerhitunganDurasiHari (int noKomp, Pengguna dataWarnet[11]) {
	float durasi;
	durasi = (
		(
			(dataWarnet[noKomp].tanggalKeluar.tanggal) +
			(
				dataWarnet[noKomp].tanggalKeluar.bulan *
				PerhitunganTahunKabisat (noKomp, "BulanKeluar", dataWarnet)
			) +
			(
				dataWarnet[noKomp].tanggalKeluar.tahun *
				PerhitunganTahunKabisat (noKomp, "TahunKeluar", dataWarnet)
			)
		) -
		(
			(dataWarnet[noKomp].tanggalMasuk.tanggal) + 
			(
				dataWarnet[noKomp].tanggalMasuk.bulan * 
				PerhitunganTahunKabisat (noKomp, "BulanMasuk", dataWarnet)
			) + 
			(
				dataWarnet[noKomp].tanggalMasuk.tahun * 
				PerhitunganTahunKabisat (noKomp, "TahunMasuk", dataWarnet)
			)
		)
	);
	return durasi;
}
 
float BiayaMakanan (int pesanan, int porsi) {
	float biayaMakanan;
	switch (pesanan) {
		case 1 : biayaMakanan = porsi * 5000; break;
		case 2 : biayaMakanan = porsi * 5000; break;
		case 3 : biayaMakanan = porsi * 10000; break;
		case 4 : biayaMakanan = porsi * 3000; break;
		case 5 : biayaMakanan = porsi * 3000; break;
		case 6 : biayaMakanan = porsi * 2500; break;
		case 7 : biayaMakanan = porsi * 3000; break;
	}
	return biayaMakanan;
}

void ResetKomp (int noKomp, Pengguna dataWarnet[11]) {
	dataWarnet[noKomp].tanggalMasuk.tanggal = 0;
	dataWarnet[noKomp].tanggalMasuk.bulan = 0;
	dataWarnet[noKomp].tanggalMasuk.tahun = 0;
	dataWarnet[noKomp].tanggalKeluar.tanggal = 0;
	dataWarnet[noKomp].tanggalKeluar.bulan = 0;
	dataWarnet[noKomp].tanggalKeluar.tahun = 0;
	dataWarnet[noKomp].jamMasuk.jam = 0;
	dataWarnet[noKomp].jamMasuk.menit = 0;
	dataWarnet[noKomp].jamMasuk.detik = 0;
	dataWarnet[noKomp].jamKeluar.jam = 0;
	dataWarnet[noKomp].jamKeluar.detik = 0;
	dataWarnet[noKomp].jamKeluar.menit = 0;
	dataWarnet[noKomp].biayaTotal = 0;
}

void RecapDataFile (int noKomp, const char ket[20], Pengguna dataWarnet[11]) {
	if (strcmp (ket, "ReadData") == 0) {
		FILE *fData;
		
		if ((fData = fopen ("Data.txt", "rb")) == NULL) {
			printf ("Error! Opening File");
			exit(1);
		} 
		
		else {
			for (int noKomp = 1; noKomp <= 10; noKomp++) {
				fread(&dataWarnet[noKomp], sizeof(dataWarnet[noKomp]), 1, fData);
			}	
		}
		
		fclose (fData);
	}
	
	if (strcmp (ket, "WriteData") == 0) {
		FILE *fData;
		fData = fopen ("Data.txt", "wb");
	
		for (int noKomp = 1; noKomp <= 10; noKomp++) {
			fwrite(&dataWarnet[noKomp], sizeof(dataWarnet[noKomp]), 1, fData);
		}
	
		fclose (fData);	
	}
	
	if (strcmp (ket, "ReadRecap") == 0) {
		FILE *fRecap;
		
		float totalBiayaRecap = 0;
		if ((fRecap = fopen ("Recap.txt", "rb")) == NULL) {
			printf ("Error! Opening File");
			exit(1);
		}
		
		else {
			while (fread (&dataWarnet[0], sizeof(dataWarnet[0]), 1, fRecap) == 1) {
				int kanan, kiri, x, i;
				printf ("|     %d", dataWarnet[0].noKomputer);
				for (int i = 1; i <= 6 - HitungDigit (dataWarnet[0].noKomputer); i++) {
					printf (" ");
				}
				
				x = (
						(27 - 
							(
								HitungDigit (dataWarnet[0].tanggalMasuk.tanggal) + 
								HitungDigit (dataWarnet[0].tanggalMasuk.bulan) + 
								HitungDigit (dataWarnet[0].tanggalMasuk.tahun) + 
								HitungDigit (dataWarnet[0].tanggalKeluar.tanggal) + 
								HitungDigit (dataWarnet[0].tanggalKeluar.bulan) + 
								HitungDigit (dataWarnet[0].tanggalKeluar.tahun) + 7
							) 
						) / 2
				);
				kiri = x;
				kanan = x + 2;
				if (
					27 - 
						(
							HitungDigit (dataWarnet[0].tanggalMasuk.tanggal) + 
							HitungDigit (dataWarnet[0].tanggalMasuk.bulan) + 
							HitungDigit (dataWarnet[0].tanggalMasuk.tahun) + 
							HitungDigit (dataWarnet[0].tanggalKeluar.tanggal) + 
							HitungDigit (dataWarnet[0].tanggalKeluar.bulan) + 
							HitungDigit (dataWarnet[0].tanggalKeluar.tahun) + 7 
						) % 2 == 1
				) {
					kanan++;	
				}
				for (i = 1; i <= kiri; i++) {
					printf (" ");
				}
				printf ("%d/%d/%d - %d/%d/%d", dataWarnet[0].tanggalMasuk.tanggal, dataWarnet[0].tanggalMasuk.bulan, dataWarnet[0].tanggalMasuk.tahun, dataWarnet[0].tanggalKeluar.tanggal, dataWarnet[0].tanggalKeluar.bulan, dataWarnet[0].tanggalKeluar.tahun);
				for (i = 1; i <= kanan; i++) {
					printf (" ");
				}
				
				x = (
						(25 - 
							(
								HitungDigit (dataWarnet[0].jamMasuk.jam) + 
								HitungDigit (dataWarnet[0].jamMasuk.menit) + 
								HitungDigit (dataWarnet[0].jamMasuk.detik) + 
								HitungDigit (dataWarnet[0].jamKeluar.jam) + 
								HitungDigit (dataWarnet[0].jamKeluar.menit) + 
								HitungDigit (dataWarnet[0].jamKeluar.detik) + 7
							) 
						) / 2
				);
				kiri = x;
				kanan = x + 1;
				for (i = 1; i <= kiri; i++) {
					printf (" ");
				}
				printf ("%d:%d:%d - %d:%d:%d", (int)dataWarnet[0].jamMasuk.jam, (int)dataWarnet[0].jamMasuk.menit, (int)dataWarnet[0].jamMasuk.detik, (int)dataWarnet[0].jamKeluar.jam, (int)dataWarnet[0].jamKeluar.menit, (int)dataWarnet[0].jamKeluar.detik);     
				for (i = 1; i <= kanan; i++) {
					printf (" ");
				}
				
				x = ((15 - HitungDigit (dataWarnet[0].biayaTotal)) / 2);
				kiri = x;
				kanan = x;
				if ((15 - HitungDigit (dataWarnet[0].biayaTotal)) % 2 == 1) {
					kanan++;	
				}
				for (i = 1; i <= kiri; i++) {
					printf (" ");
				}
				printf ("%.0f", dataWarnet[0].biayaTotal);
				for (i = 1; i <= kanan; i++) {
					printf (" ");
				}
				printf ("|\n");
				totalBiayaRecap = totalBiayaRecap + dataWarnet[0].biayaTotal;
			}
			printf ("|---------------------------------------------------------------------------------|\n");
			printf ("    Total Pendapatan Keseluruhan = ");
			SetColor(2); printf ("Rp.%.0f\n", totalBiayaRecap);
			SetColor(15);
		}
		
		fclose (fRecap);
	}
	
	if (strcmp (ket, "AppendRecap") == 0) {
		FILE *fRecap;
		fRecap = fopen ("Recap.txt", "ab");
		
		fwrite(&dataWarnet[noKomp], sizeof(dataWarnet[noKomp]), 1, fRecap);
		
		fclose (fRecap);
	}
	
	if (strcmp (ket, "ReadInfo") == 0) {
		FILE *fInfo;
		
		char text[200];
		if ((fInfo = fopen ("Info.txt", "rt")) == NULL) {
			printf ("Error! Opening File");
			exit(1);
		}
		
		else {
			while (fgets(text, sizeof(text), fInfo) != NULL) {
				printf ("%s", text);
			}
			printf ("\n");
		}
		
		fclose (fInfo);
	}
}

void CetakStruk (int noKomp, float biayaPrinter, float biayaMakanan, Pengguna dataWarnet[11]) {
	float totalDurasi;
	float bayar;
	if (PerhitunganDurasiHari (noKomp, dataWarnet) == 0) {
		totalDurasi = PerhitunganDurasiJam (noKomp, dataWarnet);	
	}
	
	if (PerhitunganDurasiHari (noKomp, dataWarnet) > 0) {
		totalDurasi = PerhitunganDurasiJam (noKomp, dataWarnet) + ((PerhitunganDurasiHari (noKomp, dataWarnet) - 1) * 24);
	}
	
	system ("cls");
	printf ("\n\t======================================================\n");
	printf ("\t|");
	SetColor(3); printf ("\t\t      MASTER.NET");
	SetColor(15); printf ("\t\t     |\n");
	printf ("\t|");
	SetColor(3); printf ("     Jl.Pesantren No.115, Cibabat, Cimahi Utara");
	SetColor(15); printf ("     |\n");
	printf ("\t|  ------------------------------------------------  |\n");
	printf ("\t|     No.Komputer  : %d\t\t\t\t     |\n", dataWarnet[noKomp].noKomputer);	
	printf ("\t|     Waktu Masuk  : %d-%d-%d  %d:%d:%d", dataWarnet[noKomp].tanggalMasuk.tanggal, dataWarnet[noKomp].tanggalMasuk.bulan, dataWarnet[noKomp].tanggalMasuk.tahun, (int)dataWarnet[noKomp].jamMasuk.jam, (int)dataWarnet[noKomp].jamMasuk.menit, (int)dataWarnet[noKomp].jamMasuk.detik);
	for (int i = 1; i <= (32 - (HitungDigit(dataWarnet[noKomp].tanggalMasuk.tanggal) + HitungDigit(dataWarnet[noKomp].tanggalMasuk.bulan) + HitungDigit(dataWarnet[noKomp].tanggalMasuk.tahun) + HitungDigit (dataWarnet[noKomp].jamMasuk.jam) + HitungDigit (dataWarnet[noKomp].jamMasuk.menit) + HitungDigit (dataWarnet[noKomp].jamMasuk.detik)) - 6); i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t|     Waktu Keluar : %d-%d-%d  %d:%d:%d", dataWarnet[noKomp].tanggalKeluar.tanggal, dataWarnet[noKomp].tanggalKeluar.bulan, dataWarnet[noKomp].tanggalKeluar.tahun, (int)dataWarnet[noKomp].jamKeluar.jam, (int)dataWarnet[noKomp].jamKeluar.menit, (int)dataWarnet[noKomp].jamKeluar.detik);
	for (int i = 1; i <= (32 - (HitungDigit(dataWarnet[noKomp].tanggalKeluar.tanggal) + HitungDigit(dataWarnet[noKomp].tanggalKeluar.bulan) + HitungDigit(dataWarnet[noKomp].tanggalKeluar.tahun) + HitungDigit (dataWarnet[noKomp].jamKeluar.jam) + HitungDigit (dataWarnet[noKomp].jamKeluar.menit) + HitungDigit (dataWarnet[noKomp].jamKeluar.detik)) - 6); i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t|     Durasi       : %.2f jam", totalDurasi);
	for (int i = 1; i <= (25 - HitungDigit (totalDurasi)); i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t|     Biaya Rental  \t\tRp.%.0f", BiayaRental (noKomp, dataWarnet));
	for (int i = 1; i <= (18 - HitungDigit (BiayaRental (noKomp, dataWarnet))); i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t|     Biaya Printer \t\tRp.%d", (int)biayaPrinter);
	for (int i = 1; i <= (18 - HitungDigit (biayaPrinter)) ; i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t|     Biaya Makanan \t\tRp.%d", (int)biayaMakanan);
	for (int i = 1; i <= (18 - HitungDigit (biayaMakanan)) ; i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t|  ------------------------------------------------  |\n");
	printf ("\t|     Total         \t\tRp.%.0f", dataWarnet[noKomp].biayaTotal);
	for (int i = 1; i <= (18 - HitungDigit (dataWarnet[noKomp].biayaTotal)); i++ ) {
		printf(" ");
	}
	printf ("|\n");
	printf ("\t======================================================\n\n");
	printf ("Uang bayar: ");
	scanf ("%f", &bayar);
	for (;;) {
		if (bayar >= dataWarnet[noKomp].biayaTotal) {
			bayar = bayar - dataWarnet[noKomp].biayaTotal;
			printf ("Kembalian = Rp.%.0f\n", bayar);
			break;
		}
		else {
			printf ("Uang tidak cukup!\n");
		}
		printf ("Uang bayar: ");
		scanf ("%f", &bayar);
	}
}

int HitungDigit (float biaya) {
	int jumlahDigit = 0;
	if ((int)biaya == 0) {
		jumlahDigit = 1;
	}
	while ((int)biaya != 0) {
		biaya /= 10;
		jumlahDigit++;
	}

	return jumlahDigit;
}

void SetColor (int ForgC) {	// Source code: "https://stackoverflow.com/questions/29574849/how-to-change-text-color-and-console-color-in-codeblocks"
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
    	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
     }
}
