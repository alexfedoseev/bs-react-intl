open PageLocale;

[@react.component]
let make = (~locale, ~setLocale) => {
  let intl = ReactIntl.useIntl();
  let className = locale' => locale' === locale ? "active" : "";

  <div className="container">
    <div className="buttons">
      <button
        className={Locale.En->className} onClick={_ => Locale.En->setLocale}>
        {Locale.En->Locale.toString->React.string}
      </button>
      <button
        className={Locale.Ru->className} onClick={_ => Locale.Ru->setLocale}>
        {Locale.Ru->Locale.toString->React.string}
      </button>
    </div>
    <div className="message">
      <ReactIntl.FormattedMessage id="page.hello" defaultMessage="Hello" />
      " "->React.string
      <ReactIntl.FormattedMessage id="page.world" defaultMessage="World" />
    </div>
    <div>
      ReactIntl.(intl->Intl.formatMessage(pageLocale##today)->React.string)
      " "->React.string
      ReactIntl.(intl->Intl.formatDate(Js.Date.make())->React.string)
      " (intl.formatDate)"->React.string
      <br />
      ReactIntl.(intl->Intl.formatMessage(pageLocale##today)->React.string)
      " "->React.string
      <ReactIntl.FormattedDate value={Js.Date.make()} />
      " (FormattedDate)"->React.string
    </div>
  </div>;
};
