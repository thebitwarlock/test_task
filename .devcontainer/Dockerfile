FROM ubuntu:24.04

# Установите инструменты
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    make \
    git \
    gdb \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Создайте пользователя 'vscode' с паролем и добавьте в sudo
RUN useradd -m -s /bin/bash vscode && \
    echo 'vscode ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# Установите рабочую директорию
WORKDIR /workspace

# Переключитесь на пользователя vscode (опционально, можно оставить root для сборки)
USER vscode