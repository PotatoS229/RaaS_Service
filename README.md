# Hello! 👋

My name is **Artemy Maksaliyev**. I'm a student at the **Moscow Power Engineering Institute (MPEI)** , where I study programming.

## 🚀 My Dream Project

My long-standing dream is to develop a **corporate-scale cybersecurity tool** that will be **completely free for all users**. To that end, I'm launching this project.

## 📊 Project Status

I'd be happy if you'd be interested in following its progress. I hope you find my work useful!

---

⭐ *If you're interested in this project, consider starring the repository to stay updated!*

```bash
RAAS/
├── .vscode/                      # Конфигурация VS Code
│   ├── launch.json               # Конфигурация отладки
│   ├── tasks.json                # Задачи сборки
│   └── settings.json             # Настройки editor
├── backend/                      # Весь backend код
│   ├── api/                      # NestJS API сервер
│   │   ├── src/
│   │   │   ├── modules/          # Модули по функционалу
│   │   │   │   ├── network/      # Сетевые операции
│   │   │   │   │   ├── dto/      # Data Transfer Objects
│   │   │   │   │   ├── controllers/
│   │   │   │   │   ├── services/
│   │   │   │   │   └── interfaces/
│   │   │   │   ├── attack/       # Модуль атак
│   │   │   │   ├── monitoring/   # Мониторинг
│   │   │   │   └── stress-test/  # Стресс-тесты
│   │   │   ├── shared/           # Общие модули
│   │   │   │   ├── middleware/
│   │   │   │   ├── guards/
│   │   │   │   ├── interceptors/
│   │   │   │   └── utils/
│   │   │   ├── config/           # Конфигурация приложения
│   │   │   ├── main.ts
│   │   │   └── app.module.ts
│   │   ├── test/
│   │   │   ├── e2e/
│   │   │   └── unit/
│   │   ├── package.json
│   │   ├── nest-cli.json
│   │   └── tsconfig.json
│   │
│   └── core/                      # C++ ядро для сетевых операций
│       ├── include/               # Публичные заголовки
│       │   ├── network/
│       │   │   ├── IConfigNetwork.h
│       │   │   ├── INetworkAttack.h
│       │   │   ├── INetworkInfo.h
│       │   │   └── IStressTest.h
│       │   └── common/
│       │       ├── Types.h
│       │       └── Logger.h
│       ├── src/                   # Исходники C++
│       │   ├── network/
│       │   │   ├── configNetwork.cpp
│       │   │   ├── networkAttack.cpp
│       │   │   ├── networkInfo.cpp
│       │   │   └── stressTest.cpp
│       │   ├── bindings/          # Связки с другими языками
│       │   │   ├── node/          # Node.js addon
│       │   │   │   ├── addon.cpp
│       │   │   │   └── binding.gyp
│       │   │   └── python/        # Если понадобится Python
│       │   └── utils/
│       │       └── logger.cpp
│       ├── tests/                 # C++ тесты
│       │   ├── unit/
│       │   └── integration/
│       ├── CMakeLists.txt
│       └── README.md
│
├── frontend/                      # React frontend
│   ├── public/
│   │   ├── favicon.ico
│   │   └── index.html
│   ├── src/
│   │   ├── api/                   # API клиенты
│   │   │   ├── client.ts
│   │   │   └── endpoints/
│   │   │       ├── network.ts
│   │   │       └── attack.ts
│   │   ├── assets/
│   │   │   ├── styles/
│   │   │   │   ├── global.css
│   │   │   │   └── variables.css
│   │   │   └── images/
│   │   ├── components/            # React компоненты
│   │   │   ├── common/            # Переиспользуемые компоненты
│   │   │   │   ├── Button/
│   │   │   │   ├── Modal/
│   │   │   │   └── Layout/
│   │   │   ├── network/           # Компоненты для сети
│   │   │   ├── attack/            # Компоненты для атак
│   │   │   └── dashboard/         # Дашборд
│   │   ├── hooks/                 # Кастомные хуки
│   │   │   ├── useNetwork.ts
│   │   │   └── useWebSocket.ts
│   │   ├── store/                 # Состояние приложения
│   │   │   ├── slices/
│   │   │   └── index.ts
│   │   ├── types/                 # TypeScript типы
│   │   │   └── index.ts
│   │   ├── utils/                 # Утилиты
│   │   │   └── formatters.ts
│   │   ├── App.tsx
│   │   ├── main.tsx
│   │   └── vite-env.d.ts
│   ├── tests/
│   │   ├── unit/
│   │   └── e2e/
│   ├── package.json
│   ├── vite.config.ts
│   ├── tsconfig.json
│   └── .eslintrc.js
│
├── infrastructure/                # Инфраструктура и DevOps
│   ├── docker/
│   │   ├── backend/
│   │   │   ├── Dockerfile
│   │   │   └── .dockerignore
│   │   ├── frontend/
│   │   │   ├── Dockerfile
│   │   │   └── .dockerignore
│   │   └── docker-compose.yml
│   ├── kubernetes/                # K8s манифесты
│   │   ├── backend-deployment.yaml
│   │   ├── frontend-deployment.yaml
│   │   └── services.yaml
│   └── scripts/                   # Скрипты для деплоя
│       ├── build.sh
│       └── deploy.sh
│
├── docs/                          # Документация
│   ├── api/                       # OpenAPI/Swagger
│   ├── architecture/              # Архитектурные решения
│   ├── user-guide/                # Пользовательская документация
│   └── developer-guide/           # Для разработчиков
│       ├── setup.md
│       └── cpp-integration.md
│
├── scripts/                       # Скрипты для разработки
│   ├── setup-dev.sh               # Установка зависимостей
│   ├── build-cpp.sh               # Сборка C++ модуля
│   └── run-tests.sh               # Запуск тестов
│
├── .gitignore
├── .env.example                    # Пример переменных окружения
├── .eslintrc.js                    # Корневой ESLint
├── .prettierrc                     # Prettier конфиг
├── CMakeLists.txt                  # Корневой CMake (опционально)
├── LICENSE.md
├── README.md                       # Главный README
└── turbo.json                      # Turborepo конфиг (если используете)
```