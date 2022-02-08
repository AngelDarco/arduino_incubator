import { Link } from "react-router-dom"
import { SwiperSlide, Swiper } from 'swiper/react';
import './Navbar.scss';
import "swiper/css";

import { Autoplay } from "swiper";

export default function Nav() {
    return (

        <Swiper className='nav'
        slidesPerView={1}
        spaceBetween={30}
        loop={true}
        autoplay={{
            delay: 3000,
            disableOnInteraction: false,
          }}
          modules={[Autoplay]}
        >
            <SwiperSlide className='navSlide'><Link className='link' to='/html' onClick={() => { redirection() }}>Html</Link> </SwiperSlide>
            <SwiperSlide className='navSlide'><Link className='link' to='/css' onClick={() => { redirection() }}>Css</Link> </SwiperSlide>
            <SwiperSlide className='navSlide'><Link className='link' to='/js' onClick={() => { redirection() }}>Js</Link> </SwiperSlide>
            <SwiperSlide className='navSlide'><Link className='link' to="/php" onClick={() => { redirection() }}>Php</Link> </SwiperSlide>
        
        </Swiper>

    )
}

function redirection(): void {
    window.location.href = '#redirection';
}
