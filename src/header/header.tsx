import React from "react";
import "./style.scss";

export const Header = ()=>{
    return<>
    <div className="container" >
        <div className="links">
        <ul>
            <ul className="pages css">Css
                <li><a className="link" href="http://darcocorporation.scienceontheweb.net/pages/css/book_cover/index.html">Book Cover</a></li>
                <li className="link"><a href="http://darcocorporation.scienceontheweb.net/pages/css/climbing_cube/index.html">Climbing Cube</a></li>
                <li className="link"><a href="http://darcocorporation.scienceontheweb.net/pages/css/cursor_effect/index.html">Cursor Effect</a></li>
            </ul>

                <li className="pages">Js</li>
                <li className="pages">Html</li>
                <li className="pages">Php</li>
                <li className="pages">React</li>
        </ul>
        </div>

        <div className="title">
            <h1 className="title">Darco Corporation</h1>
        </div>
        
    </div>
    
    </>
}


