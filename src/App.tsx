import css from './style.css'
import image from './img/woman.svg'

export const App = ()=>{
    return<> 
    <h1 style={css} >Webpack with Typescript and React Working ...</h1>
    <img src={image} alt="My Svg" width="300" height="200" />
    
    </>
}