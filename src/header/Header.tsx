import Navbar from './navbar/Navbar';
import Main from './main/Main'

const Header = ()=>{
    return(
        <div style={styles}>
            <Navbar/>
            <Main/>
        </div>
    )
}
export default Header;

const styles ={
    width: '100%',
    height: '100vh',
    border: '1px solid red'
}