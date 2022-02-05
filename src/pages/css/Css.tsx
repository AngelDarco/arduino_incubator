import './Css.scss';
import {SwiperSlide, Swiper} from 'swiper/react';
import {CssImages, CssLinks } from '../../assets/videos/css/Images';
import 'swiper/css';

const Css = () => {
    return (
                  <Swiper className="containerCss">
                   <SwiperSlide className="card"> <img src={CssImages.book} alt="" onClick={()=>translate(CssLinks.book)}/>   </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.card} alt="" onClick={()=>translate(CssLinks.card)}/>    </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.cube} alt="" onClick={()=>translate(CssLinks.cube)}/>    </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.earth} alt="" onClick={()=>translate(CssLinks.earth)}/>  </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.loader} alt="" onClick={()=>translate(CssLinks.loader)}/></SwiperSlide>
                   </Swiper>
    )
}
function translate(name:string):void{
    window.open(name);
}


export default Css;