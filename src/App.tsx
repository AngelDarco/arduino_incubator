import css from './style.css'
import image from './assets/img/woman.svg'

import {Header} from './header/header.tsx'

export const App = ()=>{
    return<> 
    <Header/>
    <h1 style={css} >Webpack with Typescript and React Working ...</h1>
    <img src={image} alt="My Svg" width="300" height="200" />
    
    </>
}