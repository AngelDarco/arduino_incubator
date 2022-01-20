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
                    <Link href='/html' >Html</Link>
                    <Link href='/css'  >Css  </Link>
                    <Link href='/js' >Js  </Link>
                    <Link href="/php" >Php </Link>
                </nav>
            </div>

        </div>


    )
}

export default Navbar;

