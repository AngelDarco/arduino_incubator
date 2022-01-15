import logo from '../assets/img/icono.webp';
import "./style.scss";

export const Header = () => {
    return <>
        <div className="container" >

            <div className="logo">
                <img src={logo} alt="D" />
            </div>

            <div className="title">
                <h1>Darco Corporation</h1>
            </div>

            <div className="links">
                <ul className='ul__pages'>
                    <ul className="pages">Css
                        <ul className="link" >
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/book_cover/index.html">Book Cover</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/index.html">Climbing Cube</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/cursor_effect/index.html">Cursor Effect</a>
                        </ul>
                    </ul>

                    <ul className="pages">Js
                        <ul className="link" >
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/book_cover/index.html">Book Cover</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/index.html">Climbing Cube</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/cursor_effect/index.html">Cursor Effect</a>
                        </ul>
                    </ul>

                    <ul className="pages">Html
                        <ul className="link" >
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/book_cover/index.html">Book Cover</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/index.html">Climbing Cube</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/cursor_effect/index.html">Cursor Effect</a>
                        </ul>
                    </ul>

                    <ul className="pages">Php
                        <ul className="link" >
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/book_cover/index.html">Book Cover</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/index.html">Climbing Cube</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/cursor_effect/index.html">Cursor Effect</a>
                        </ul>
                    </ul>

                    <ul className="pages">React
                        <ul className="link" >
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/book_cover/index.html">Book Cover</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/index.html">Climbing Cube</a>
                            <a href="http://darcocorporation.scienceontheweb.net/pages/css/cursor_effect/index.html">Cursor Effect</a>
                        </ul>
                    </ul>

                </ul>
            </div>

        </div>

    </>
}

function visivility() {
    let title = document.querySelectorAll('.pages');
    for (let i in title) {
        console.log(i);
    }
}

