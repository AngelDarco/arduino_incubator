import { Link} from 'wouter';
import logo from '../../assets/img/icono.webp';

import "./Navbar.scss";


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
                <nav>
                    <Link className='link' href='/html' onClick={()=>{redirection()}}>Html</Link>
                    <Link className='link' href='/css' onClick={()=>{redirection()}}>Css</Link>
                    <Link className='link' href='/js' onClick={()=>{redirection()}}>Js</Link>
                    <Link className='link' href="/php" onClick={()=>{redirection()}}>Php</Link>
                </nav>
            </div>

        </div>


    )
}
function redirection():void{
    window.location.href = '#redirection';
}
export default Navbar;

