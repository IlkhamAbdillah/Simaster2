#include "Mahasiswa.h"
#include "Activity.h"

void Mahasiswa::markActivity() {
    if(Activity::activityList.empty()){
        std::cout << "Tidak ada aktivitas";
        exit(0);
    }
    else{
        int x;
        char y;
        Activity::showActivityList();
        std::cout << "Pilih nomor aktivitas untuk ditandai : ";
        std::cin >> x;
        if(Activity::activityList[x-1].status != "Selesai"){
            std::cout << "Tandai sebagai selesai? (y/n) : ";
            std::cin >> y;
            if(y=='y'){
                Activity::activityList[x-1].status = "Selesai";
                std::cout<<"Aktivitas " << x << " berhasil diselesaikan" << std::endl;
            }
        }
    }
}