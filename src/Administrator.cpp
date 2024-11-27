#include "Administrator.h"
#include "ManageActivity.h"

void Admin::accessAdd() {
    manageActivity::addActivity();
}

void Admin::accessDelete(){
    manageActivity::deleteActivity();
}