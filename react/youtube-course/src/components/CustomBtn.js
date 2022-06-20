const CustomBtn = ({ children, ...props }) => {
  return (
    <button {...props} style={{ margin: 5, padding: 5, fontSize: 18 }}>
      {children}
    </button>
  )
}

export default CustomBtn;