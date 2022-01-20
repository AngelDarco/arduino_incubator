import Bottom from './bottom/Bottom';
import Navbar from './navbar/Navbar'

const Header = ()=>{
    return(
        <div style={styles}>
            <Navbar/>
            <Bottom/>
            
        </div>
    )
}
export default Header;

const styles ={
    width: '100%',
    height: '100vh',
    border: '1px solid red'
}