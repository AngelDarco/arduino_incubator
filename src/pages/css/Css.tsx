import './Css.scss';
import 'swiper/css';
import {SwiperSlide, Swiper} from 'swiper/react';
import {CssImages, CssLinks } from '../../assets/videos/css/Images';
import {AiOutlineArrowLeft,AiOutlineArrowRight} from 'react-icons/ai';
import {BsFillPlayFill} from 'react-icons/bs';

const Css = () => {
    return (
                  <Swiper className="containerCss">
                    <AiOutlineArrowLeft className='icon'/>
                   <SwiperSlide className="card"> <img src={CssImages.book} alt="" onClick={()=>translate(CssLinks.book)}/> <BsFillPlayFill className="icon play"   onClick={()=>translate(CssLinks.book)}/>  </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.card} alt="" onClick={()=>translate(CssLinks.card)}/>  <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.card)} />   </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.cube} alt="" onClick={()=>translate(CssLinks.cube)}/>  <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.cube)} />   </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.earth} alt="" onClick={()=>translate(CssLinks.earth)}/> <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.earth)}/>  </SwiperSlide>
                   <SwiperSlide className="card"> <img src={CssImages.loader} alt="" onClick={()=>translate(CssLinks.loader)}/> <BsFillPlayFill className="icon play"  onClick={()=>translate(CssLinks.loader)}/></SwiperSlide>
                   <AiOutlineArrowRight className='icon right'/>
                   </Swiper>
    )   
}
function translate(name:string):void{
    window.open(name);
}

export default Css;

