import './Css.scss';
import 'swiper/css';
import {SwiperSlide, Swiper} from 'swiper/react';
import {CssImages, CssLinks } from '../../assets/videos/css/Images';
import {BsFillPlayFill} from 'react-icons/bs';
import { Autoplay } from 'swiper';



const Css = () => {
    return (
                  <Swiper className="containerCss"
                  loop={true}
                  autoplay={{
                      delay: 5000,
                      disableOnInteraction: false,
                    }}
                    modules={[Autoplay]}
                  >
                   <SwiperSlide className="card"> <img src={CssImages.book} alt="" onClick={()=>translate(CssLinks.book)}/> <BsFillPlayFill className="icon play"   onClick={()=>translate(CssLinks.book)}/>  </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.card} alt="" onClick={()=>translate(CssLinks.card)}/>  <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.card)} />   </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.cube} alt="" onClick={()=>translate(CssLinks.cube)}/>  <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.cube)} />   </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.earth} alt="" onClick={()=>translate(CssLinks.earth)}/> <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.earth)}/>  </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.loader} alt="" onClick={()=>translate(CssLinks.loader)}/> <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.loader)}/></SwiperSlide>
                   </Swiper>
    )   
}
function translate(name:string):void{
    window.open(name);
}

export default Css;

