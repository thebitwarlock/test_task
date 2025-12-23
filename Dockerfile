FROM ubuntu:24.04

# Устанавливаем компиляторы, CMake и системные утилиты
# Флаг -y автоматически отвечает "yes" на все запросы
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    make \
    git \
    && rm -rf /var/lib/apt/lists/* # Очищаем кеш для уменьшения размера образа

# Устанавливаем рабочую директорию внутри контейнера
WORKDIR /workspace

# Указываем команду по умолчанию при запуске контейнера
CMD ["/bin/bash"]