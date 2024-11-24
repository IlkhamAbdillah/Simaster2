#include "Administrator.h"
#include "ManageActivity.h"

void Admin::accessAdd() {
    manageActivity::addActivity();
}

void Admin::accessErase(){
    manageActivity::eraseActivity();
}