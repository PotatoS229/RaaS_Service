import './Menu.css';
import {Link} from 'react-router-dom'
import MenuButton from '../../components/MenuButton/MenuButton.tsx'

const MenuPage = () => {
    return (
    <div className="dashboard-card">
        <div className="welcome-header">
            <h1>⚙️ Панель управления</h1>
            <p>RaaS Service • выберите модуль для настройки</p>
        </div>
        <div className="main-layout">

            <aside className="menu-aside">
                <h2>📋 Меню возможностей</h2>
                <div className="menu-grid">


                    <div className='testBlack'>
                        <p>RAW Sockets</p>

                        <p>Proteus (логотип хамелеона)</p>

                        <p>Impersonator</p>

                        <p>Autopilot (AI)</p>

                        <p>Recon (OSINT)</p>

                        <p>P2P Mesh</p>

                        <p>Dry Run</p>

                        <p>Integrations</p>

                        <p>Orchestrator</p>

                        <p>Metrics</p>

                        <p>Arsenal</p>

                        <p>Graph</p>
                    </div>    



                    <MenuButton index={1} name={"Низкоуровневые сетевые взаимодействия (raw sockets, манипуляция пакетами)"}></MenuButton>

                    <MenuButton index={2} name={"Полиморфная эвазия (Proteus-режим) — динамическое переключение протоколов"}></MenuButton>

                    <MenuButton index={3} name={"Impersonation Engine — имитация человеческого поведения"}></MenuButton>

                    <MenuButton index={4} name={"Автономный Red Team Assistant — принятие решений на основе контекста и построение цепочек атак"}></MenuButton>

                    <MenuButton index={5} name={"OSINT-движок — интеграция с Shodan, GitHub и поиск утечек"}></MenuButton>

                    <MenuButton index={6} name={"C2-фреймворк с P2P сетью агентов"}></MenuButton>

                    <MenuButton index={7} name={"Безопасный режим (песочница, прогноз урона"}></MenuButton>

                    <MenuButton index={8} name={"Интеграции и отчетность (экспорт в Jira, SIEM, генерация доказательной базы)"}></MenuButton>

                    <MenuButton index={9} name={"DevOps и инфраструктура (оркестрация агентов, масштабирование)"}></MenuButton>

                    <MenuButton index={10} name={"Дашборд статистики"}></MenuButton>

                    <MenuButton index={11} name={"Панель управления атаками"}></MenuButton>

                    <MenuButton index={12} name={"Визуализация графа атак с предиктивными векторами"}></MenuButton>

                </div>
            </aside>


            <div className="content-preview">
                <div className="placeholder-icon">📊</div>
                <h3>Сводка по выбранному модулю</h3>
                <p>Здесь появится интерфейс настройки, визуализация или результаты работы модуля, выбранного слева. Используйте меню для навигации.</p>
                

                <div className="mock-stat">
                    <div className="mock-stat-item">
                        <div className="label">активные агенты</div>
                        <div className="value">18</div>
                    </div>
                    <div className="mock-stat-item">
                        <div className="label">задач в очереди</div>
                        <div className="value">7</div>
                    </div>
                    <div className="mock-stat-item">
                        <div className="label">поверхность</div>
                        <div className="value">143</div>
                    </div>
                </div>

            </div>
        </div>


        <div className="footer-links">
            <span>© 2025 RaaS Service</span>
            <span>
                <Link to='/auth'>🔄 Сменить профиль</Link> • <Link to="/">Настройки</Link>
            </span>
        </div>
    </div>
    )
}

export default MenuPage;


  