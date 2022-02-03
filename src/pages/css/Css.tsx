import './Css.scss';
import {CssImages, CssLinks } from '../../assets/videos/css/Images';

const Css = () => {
    return (
            <div className="containerCss">
                <div className="containerSlider">
                    <div className="card"><img src={CssImages.book} alt="" onClick={()=>translate(CssLinks.book)} /></div>
                    <div className="card"><img src={CssImages.card} alt="" onClick={()=>translate(CssLinks.card)}/></div>
                    <div className="card"><img src={CssImages.cube} alt="" onClick={()=>translate(CssLinks.cube)}/></div>
                    <div className="card"><img src={CssImages.earth} alt="" onClick={()=>translate(CssLinks.earth)}/></div>
                    <div className="card"><img src={CssImages.loader} alt="" onClick={()=>translate(CssLinks.loader)}/></div>
                </div>
            </div>                   
    )
}
function translate(name:string):void{
    window.open(name);
}

export default Css;