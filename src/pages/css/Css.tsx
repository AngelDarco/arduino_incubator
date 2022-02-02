import Images from '../../assets/videos/css/Images';
import './Css.scss'

const Css = () => {
    return (
        <>
            <div className="ContainerCss">
                <div className="card"><img src={Images.book} alt="" /></div>
                <div className="card"><img src={Images.card} alt="" /></div>
                <div className="card"><img src={Images.cube} alt="" /></div>
                <div className="card"><img src={Images.earth} alt="" /></div>
                <div className="card"><img src={Images.loader} alt="" /></div>
            </div>
                                
        </>
    )
}

export default Css;