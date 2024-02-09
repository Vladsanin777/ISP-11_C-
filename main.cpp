#include <iostream>
#include <discord_cpp/client.h>
#include <telegraf/telegraf.h>
#include <>


using namespace std;


void startDiscordBot(const std::string& token) {
  discord::Client client(token);
  // ... your Discord bot logic here ...

  client.run();
}

void startTelegramBot(const std::string& token) {
    TgBot bot(token);  // Create Telegram bot instance

    // Обрабатываем команды Telegram бота здесь
    bot.onCommand("start", [](TgBot::Message::Ptr message) {
     message->reply("Приветствую из Telegram!");
    });

    // ... другие обработчики команд Telegram ...

    bot.start();
}


int main() {
  std::thread discordThread(startDiscordBot, "YOUR_DISCORD_TOKEN");
  std::thread telegramThread(startTelegramBot, "YOUR_TELEGRAM_TOKEN");

  discordThread.join();
  telegramThread.join();

  return 0;
}
