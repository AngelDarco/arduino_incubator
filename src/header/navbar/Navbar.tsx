import logo from '../../assets/img/icono.webp';

import "./Navbar.scss";
import Nav from './Nav';

const Navbar = () => {
    return (
        <div className="container" >

            <div className="logo">
                <img src={logo} alt="D" />
            </div>

            <div className="title">
                <h1>Darco Corporation</h1>
            </div>

            <div className="links">
                <Nav/>
            </div>

        </div>


    )
}
function redirection():void{
    window.location.href = '#redirection';
}



export default Navbar;

