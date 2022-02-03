import './Bottom.scss';
import { Routes,Route} from 'react-router-dom';
import  Html from '../../pages/html/Html';
import  Css  from '../../pages/css/Css';
import Php from '../../pages/php/Php';
import Js from '../../pages/js/Js';

const Bottom = ()=>{

    return(
    <div className="containerBottom" id='redirection'>
      <Routes>
            
            <Route path="/html" element={<Html/>} />

            <Route path="/css" element={<Css/>}/>

            <Route path="/js" element={<Js/>}/>
                
            <Route path="/php" element={<Php/>}/>
              
        </Routes>

    </div>
    )
}

export default Bottom;