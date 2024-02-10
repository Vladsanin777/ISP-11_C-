#include <iostream>
#include <random>
#include <string>

using namespace std;

class Crypt {
public:
  // Функция генерации случайного ключа
  int generateKey() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);
    return dist(gen);
  }

  // Функция шифрования
  string encrypt(string text, int key) {
    if (text.empty()) {
      return "";
    }
    string encryptedText;
    for (char c : text) {
      encryptedText += (char)(c ^ key);
    }
    return encryptedText;
  }

  // Функция расшифрования
  string decrypt(string encryptedText, int key) {
    if (encryptedText.empty()) {
      return "";
    }
    string decryptedText;
    for (char c : encryptedText) {
      decryptedText += (char)(c ^ key);
    }
    return decryptedText;
  }
};

int setup() {
  string user_command;
  cout << "Введите существующую команду: ";
  getline(cin, user_command);
  cout << endl;

  // Измените тип user_command на int
  int command = -1;
  if (user_command == "-en") {
    command = 0;
  } else if (user_command == "-de") {
    command = 1;
  }

  switch (command) {
    case 0: {
      string text;
      cout << "Введите текст который надо зашифровать: ";
      getline(cin, text);
      cout << endl;

      Crypt crypt;
      int key = crypt.generateKey();
      string entext = crypt.encrypt(text, key);
      cout << "Ключ: " << key << endl;
      cout << "Зашифрованный текст: " << entext << endl;
      break;
    }
    case 1: {
      string encryptedText;
      cout << "Введите текст который надо расшифровать: ";
      getline(cin, encryptedText);
      cout << endl;

      Crypt crypt;
      int key;
      cout << "Введите ключ: ";
      cin >> key;
      string decryptedText = crypt.decrypt(encryptedText, key);
      cout << "Расшифрованный текст: " << decryptedText << endl;
      break;
    }
    default:{
      cout << "Такой команды не существует!" << endl;
    }
  }
  setup();
  return 0;
}

int main() {
  setup();
  return 0;
}
