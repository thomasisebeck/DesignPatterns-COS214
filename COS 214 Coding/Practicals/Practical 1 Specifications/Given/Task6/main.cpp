#include <iostream>
using namespace std;
#include "UserManager.h"
#include "User.h"

void Run();

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));
    Run();

    return 0;
}

void Run() {

  User *user = new User("username", "mysecretpassword");
  UserManager* userManager = new UserManager(user);
  userManager->Backup();
  user->SetPassword("pa$$w0rd");
  userManager->Backup();
  user->SetPassword("5t@rw@r5");
  userManager->Backup();
  userManager->ShowHistory();

  user->SetPassword("bigB@ng");
  cout << endl;
  userManager->ShowHistory();
  cout << endl << "Client: Now, let's rollback!" << endl;
  userManager->Undo();
  cout << "Client: Once more!" << endl;
  userManager->Undo();
  userManager->Undo();

  delete user;
  delete userManager;

}

